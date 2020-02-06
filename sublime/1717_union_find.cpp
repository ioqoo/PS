#include <bits/stdc++.h>
using namespace std;

int N, M;
int parent[1000001];

int find(int node){
	if (parent[node] == -1) return node;
	parent[node] = find(parent[node]);
	return parent[node];
}

void merge(int node1, int node2){
	int root1 = find(node1);
	int root2 = find(node2);
	if (root1 == root2) return;
	parent[root1] = root2;
}


int main(){
	scanf("%d %d", &N, &M);

	memset(parent, -1, (N+1) * sizeof(int));

	for (int X=0;X<M;X++){
		int op, a, b; // op - 1: merge, 0: same?
		scanf("%d %d %d", &op, &a, &b);
		if (op == 0) merge(a, b);
		else if (op == 1) {
			if (find(a) == find(b)) printf("YES\n");
			else printf("NO\n");
		}
	}
	for (int i=0;i<N;i++){
		printf("%d ", parent[i]);
	}
}