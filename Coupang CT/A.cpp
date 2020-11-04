#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll prod(int N, int k){
	ll ret = 1;
	while(N>1){
//		printf("%d\n", N);
		if (N%k != 0){
			ret *= N%k;
		}
		N /= k;
	}
	if (N != 0) ret *= N;
	return ret;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	printf("%lld\n", prod(10, 4));
	
	return 0;
}


