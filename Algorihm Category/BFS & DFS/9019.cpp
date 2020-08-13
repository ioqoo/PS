#include <bits/stdc++.h>
#define pii pair<int, int>
const int MAX = 10005;
using namespace std;

int dist[MAX];
pii pre[MAX];

int D(int n){
	return (n*2)%10000;
}

int S(int n){
	return (n+10000-1)%10000;
}

int L(int n){
	int a = (n%1000)*10;
	int b = n/1000;
	return a + b;
}

int R(int n){
	int b = n/10;
	int a = (n%10) * 1000;
	return a + b;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	scanf("%d", &t);
	while(t--){
		int A, B;
		scanf("%d %d", &A, &B);
		memset(dist, -1, sizeof(dist));
		memset(pre, -1, sizeof(pre));
		dist[A] = 0;
		queue<int> Q;
		Q.push(A);
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			if (curr == B) break;
			
			vector<int> nexts = {D(curr), S(curr), L(curr), R(curr)};
			
			for (int i=0;i<4;i++){
				int next = nexts[i];
				if (dist[next] != -1) continue;
				dist[next] = dist[curr] + 1;
				pre[next] = {curr, i};
				Q.push(next);
			}
		}
		
		vector<int> ans;
		for (int curr = B; curr != A; curr = pre[curr].first){
			ans.push_back(pre[curr].second);
		}
		for (auto it = ans.rbegin();it!=ans.rend();it++){
			int c = *it;
			if (c == 0) printf("D");
			else if (c== 1) printf("S");
			else if (c == 2) printf("L");
			else if (c == 3) printf("R");
		}
		printf("\n");
	}
	
	return 0;
}

