#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE

    ll n;
    scanf("%lld", &n);
    if (n==1LL){
    	printf("0");
    	return 0;
    }
    else if (n <= 7LL){
    	printf("1");
    	return 0;
    }
    for (ll i=2LL;i<=1000LL;i++){
    	if (n <= (i+1LL)*(1LL<<(i+1)) - 1LL){
    		printf("%lld", i);
    		break;
    	}
    }
}