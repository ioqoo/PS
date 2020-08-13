#include <bits/stdc++.h>
const int MAX = 105;
using namespace std;

struct co{
	int x, y;
	
};

int N, M;
co moles[MAX]; // ***1-index***
vector<int> graph[MAX];
bool is_known[MAX];
vector<int> unknown_list;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d %d", &N, &M);
	for (int i=1;i<=N;i++){
		int x, y;
		scanf("%d %d", &x, &y);
		moles[i] = {x, y};
		if (x!=-1 && y!=-1) {
			is_known = true;
		}
		else{
			unknown_list.push_back(i);
		}
	}
	
	for (int i=0;i<M;i++){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for (auto 
	
	return 0;
}

