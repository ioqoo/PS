#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define INF 123456789
using namespace std;

int N, M, indgree[1000];
vector<int> graph[1000];
vector<int> ans;
queue<int> Q;

int main(){
	scanf("%d %d", &N, &M);
	for (int i=0;i<M;i++){
		int K, prev, curr;
		scanf("%d", &K);

		scanf("%d", &prev);
		for (int j=1;j<K;j++){
			scanf("%d", &curr);
			indgree[curr-1]++;
			graph[prev-1].push_back(curr-1);
			prev = curr;
		}
	}

	for (int i=0;i<N;i++){
		if (indgree[i]==0) Q.push(i);
	}

	for (int i=0;i<N;i++){
		if (Q.empty()){
			printf("0");
			return 0;
		}

		int curr = Q.front();
		Q.pop();
		ans.push_back(curr+1);
		for (auto next: graph[curr]){
			if (--indgree[next]==0) Q.push(next);
		}
	}

	for (auto n: ans){
		printf("%d\n", n);
	}
}