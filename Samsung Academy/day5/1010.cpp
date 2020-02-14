#include <bits/stdc++.h>
#define MAX 10005
#define ll long long
#define MOD 10007LL

using namespace std;

ll grid[31][31]; //nCk



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
    int T;
    scanf("%d", &T);
    
    for (int i=0;i<T;i++){
    	ll n, m;
    	scanf("%lld %lld", &n, &m);
    	printf("%lld\n", comb(m, n));
	}
    
    return 0;
}
