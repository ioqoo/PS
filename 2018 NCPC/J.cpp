#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll a, b, c, d;
	scanf("%lld %lld %lld %lld\n", &a, &b, &c, &d);
	ll zero_cnt = floor(sqrt(2*a))+1;
	ll one_cnt = floor(sqrt(2*d))+1;
	if (zero_cnt * (zero_cnt-1) / 2 != a) {
		printf("impossible\n");
		return 0;
	}
	if (one_cnt * (one_cnt-1) / 2 != d){
		printf("impossible\n");
		return 0;
	}
//	printf("%lld %lld\n", zero_cnt, one_cnt);
	if (b == 0 && c == 0){
		if (a == 0 && d == 0) {
			printf("0");
			return 0;
		}
		else if (a == 0){
			for (int i=0;i<one_cnt;i++){
				printf("1");
			}
			return 0;
		}
		else if (d == 0){
			for (int i=0;i<zero_cnt;i++){
				printf("0");
			}
			return 0;
		}
	}
//	printf("%lld %lld\n", zero_cnt, one_cnt);
	vector<int> ans((zero_cnt + one_cnt)*2);
	if ( b+c != zero_cnt*one_cnt ) {
		printf("impossible\n");
		return 0;
	}
	else{
		ll div_base = b / one_cnt;
		ll div_last = div_base + (b%one_cnt);
//		printf("%lld %lld\n", div_base, div_last);
		int piv = 0;
		for (int i=0;i<one_cnt-1;i++){
			ans[div_base+piv] = 1;
			piv++;
		}
		ans[div_last+piv] = 1;
	}
	for (int i=0;i<zero_cnt+one_cnt;i++){
		printf("%d", ans[i]);
	}
	
	
	return 0;
}


