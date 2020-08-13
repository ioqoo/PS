#include <bits/stdc++.h>

using namespace std;

int N;
int dist[22][22];
bool notused[22][22];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d", &N);
	
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			scanf("%d", &dist[i][j]);
		}
	}
	int ans = 0;
	for (int k=0;k<N;k++){
		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++){
				if (i==j || j==k || k==i) continue;
				if (dist[i][k] + dist[k][j] == dist[i][j]){
					notused[i][j]= true;
				}
				else if (dist[i][k] + dist[k][j] < dist[i][j]){
					printf("-1");
					return 0;
				}
			}
		}
	}
	
	for (int i=0;i<N;i++){
		for (int j=i;j<N;j++){
			if (!notused[i][j]) ans += dist[i][j];
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}


