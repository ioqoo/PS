#include <bits/stdc++.h>
#define ll long long
const int MAX = 105;
using namespace std;

struct co{
	int x, y;
};


unordered_map<string, int> name;
unordered_map<int, string> inv;
co coor[MAX];
int N, M;
int indeg[MAX];
vector<int> graph[MAX];
unordered_set<int> fired;

ll get_dist(int i, int j){
	ll a = coor[i].x - coor[j].x;
	ll b = coor[i].y - coor[j].y;
	return a*a + b*b;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		memset(indeg, -1, sizeof(indeg));
		fill(graph, graph+MAX, vector<int>());
		name.clear();
		fired.clear();
		
		cin >> N >> M;
		for (int i=0;i<N;i++){
			string curr;
			int x, y;
			cin >> curr >> x >> y;
			name[curr] = i;
			inv[i] = curr;
			coor[i] = {x, y};
		}
		
		for (int i=0;i<M;i++){
			string s1, s2, s3, dummy;
			cin >> s1 >> dummy >> s2 >> dummy >> dummy >> s3;
			int n1 = name[s1], n2 = name[s2], n3 = name[s3];
			if (indeg[n2] == -1) indeg[n2] = 0;
			if (indeg[n3] == -1) indeg[n3] = 0;
			fired.insert(n2); fired.insert(n3);
			ll d1 = get_dist(n1, n2), d2 = get_dist(n1, n3);
//			cout << d1 << " " << d2 << endl;
			graph[n2].push_back(n3);
			indeg[n3]++;
//			if (d1 >= d2){
//				graph[n2].push_back(n3);
//				indeg[n3]++;
//			}
//			else{
//				graph[n3].push_back(n2);
//				indeg[n2]++;
//			}
		}
		
		queue<int> Q;
		for (int i=0;i<N;i++){
//			cout << indeg[i] << " ";
			if (indeg[i] == 0) {
				Q.push(i);
			}
		}
//		cout << endl;
		bool imposs = false;
		bool unknown = false;
		vector<int> ans;
		for (int i=0;i<fired.size();i++){
			if (Q.empty()){
				imposs = true;
				break;
			}
			if (Q.size() != 1){
				unknown = true;
			}
			int curr = Q.front(); Q.pop();
//			cout << curr << endl;
			ans.push_back(curr);
			for (int next: graph[curr]){
				if (--indeg[next] == 0) {
					Q.push(next);
				}
			}
		}
		if (imposs){
			cout << "IMPOSSIBLE\n";
		}
		else if (unknown){
			cout << "UNKNOWN\n";
		}
		else {
			for (auto n: ans){
				cout << inv[n] << " ";
			}
			cout << "\n";
		}
		
	}
	
	return 0;
}


