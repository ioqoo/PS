#include <bits/stdc++.h>
#define MAX 102
#define INF 1000000000LL
#define ll long long
#define MOD 10007LL

using namespace std;

string ans;
ll grid[MAX][MAX];
ll N, M, K;


void find(ll a, ll z, ll cnt){
	if (a == 0LL){
		while(z > 0LL){
			ans = ans + 'z';
			z--;
		}
		return;
	}
	else if (z == 0LL){
		while(a > 0LL){
			ans = ans + 'a';
			a--;
		}
		return;
	}
	
	ll c = grid[a-1][z];
	if (cnt <= c) {
		ans = ans + 'a';
		find(a-1, z, cnt);
	}
	else{
		ans = ans + 'z';
		find(a, z-1, cnt-c);
	}
	return;
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
    
    
    cin >> N >> M >> K;
    
    for (ll i=0LL;i<=N;i++){
    	for (ll j=0LL;j<=M;j++){
    		if (i==0 || j==0) grid[i][j] = 1LL;
    		else{
    			ll prev = grid[i][j-1] * (i+j) / j;
    			if (prev > INF) prev = INF+1LL;
    			grid[i][j] = prev;
			}
		}
	}
	
//	for (int i=0;i<10;i++){
//		for (int j=0;j<10;j++){
//			printf("%10lld ", grid[i][j]);
//		}
//		printf("\n");
//	}
    
    if (grid[N][M] < K) {
    	cout << "-1\n";
    	return 0;
	}
    
    find(N, M, K);
    cout << ans;
    
    
        
    return 0;
}
