#include <bits/stdc++.h>
#define ll long long
const int MAX = 2000005;
using namespace std;

int arr[MAX];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;
	scanf("%d", &N);
	for (int i=0;i<N;i++){
		int temp;
		scanf("%d", &temp);
		arr[temp]++;
	}
	ll ans = 0;
	for (int i=1;i<MAX;i++){
		ll curr_cnt = 0;
		for (int j=1;i*j<=MAX;j++){
			curr_cnt += arr[i*j];
		}
		if (curr_cnt < 2) continue;
		ans = max(ans, (ll)i * curr_cnt);
	}
	printf("%lld\n", ans);
	
	
	return 0;
}


