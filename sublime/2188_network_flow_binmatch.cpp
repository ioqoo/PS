#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define piii pair<pair<int, int>, int>
#define pddi pair<pair<double, double>, int>
#define plll pair<pair<ll, ll>, ll>
#define vb vector<bool>
#define vi vector<int>
#define vl vector<ll>
#define vpii vector<pii>
#define vpdd vector<pdd>
#define fi first
#define se second
#define INF 1000000000000000000LL
#define MAX 1234567890
#define MAX_V 402

using namespace std;

int n, m;
int C[MAX_V][MAX_V];
int F[MAX_V][MAX_V];
vi graph[MAX_V];

int main() {
	scanf("%d %d", &n, &m);
	for (int i=1;i<=n;i++){
		graph[0].push_back(i);
		C[0][i] = 1;
		graph[i].push_back(0);
	}
	for (int i=1;i<=n;i++){
		int mm;
		scanf("%d", &mm);
		for (int j=1;j<=mm;j++){
			int v;
			scanf("%d", &v);
			graph[i].push_back(n+v); // 축사 번호는 n+1번부터
			C[i][n+v] = 1;
			graph[n+v].push_back(i);

			graph[n+v].push_back(n+m+1); // 모든 축사가 들어갈 E는 n+m+1번
			C[n+v][n+m+1] = 1;
			graph[n+m+1].push_back(n+v);
		}
	}

	int ans = 0;
	while(1){
		int prev[MAX_V];
		fill(prev, prev+MAX_V, -1);
		queue<int> Q;
		Q.push(0);
		while(!Q.empty() && prev[n+m+1] == -1){
			int curr = Q.front();
			Q.pop();
			for (int next: graph[curr]){
				if (C[curr][next] - F[curr][next] > 0 && prev[next]==-1){
					Q.push(next);
					prev[next] = curr;
					if (next == n+m+1) break;
				}
			}
		}
		if (prev[n+m+1] == -1) break;

		int flow = MAX;
		for (int i=n+m+1;i!=0;i=prev[i]){
			flow = min(flow, C[prev[i]][i] - F[prev[i]][i]);
		}
		for (int i=n+m+1;i!=0;i=prev[i]){
			F[prev[i]][i] += flow;
			F[i][prev[i]] -= flow;
		}
		ans += flow;
	}
	printf("%d\n", ans);
}

