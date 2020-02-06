#include <bits/stdc++.h>
using namespace std;

int N, M;
int uf_p[1000];
int cost;
vector<pair<int, pair<int, int>>> edge;

int find(int node){
	if (uf_p[node] == -1) return node;
	uf_p[node] = find(uf_p[node]);
	return uf_p[node];
}

bool merge(int a, int b){ // 같은 컴포넌트에 있는지 확인해서
	int root1 = find(a);
	int root2 = find(b);
	if (root1 == root2) return false; // merge 안되면 false
	uf_p[root1] = root2;
	return true; // 되면 true 반환
}

int main(){
	scanf("%d %d", &N, &M);
	fill(uf_p, uf_p+N, -1);
	for (int i=0;i<M;i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edge.push_back(make_pair(w, make_pair(u-1, v-1)));
	}
	sort(edge.begin(), edge.end());

	int edge_cnt = 0;
	for (auto &p: edge){
		int w = p.first;
		int u = p.second.first, v = p.second.second; // u -> v
		if (merge(u, v)) {
			edge_cnt++;
			cost += w;
		}
		if (edge_cnt == N-1) break;
	}
	printf("%d\n", cost);

}