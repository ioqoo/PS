#include <bits/stdc++.h>
#define MAX 100005
#define INF 987654321

using namespace std;

int T;
int n, x;
int dist[MAX];


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
	
	scanf("%d", &T);
	for (int t=0;t<T;t++){
		scanf("%d %d", &n, &x);
		for (int i=0;i<n;i++){
			scanf("%d", &dist[i]);
		}
		sort(dist, dist+n);

		int ans = INF;
		for (int i=n-1;i>=0;i--){
			if (dist[i] > x) {
				ans = min(ans, 2);
			}
			else if (dist[i] == x){
				ans = min(ans, 1);
			}
			else if (x % dist[i]==0) {
				ans = min(ans, x/dist[i]);
			}
			else{
				ans = min(ans, x/dist[i] + 1);
			}
		}
		printf("%d\n", ans);
		
	}
	
}
