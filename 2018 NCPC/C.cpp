#include <bits/stdc++.h>

using namespace std;

int N, ans;
int arr[10000];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i=0; i<N; ++i) cin >> arr[i];
	
	int cnt = 1;
	int temp = 0;
	int pre = arr[0];
	
	for(int i=1; i<N; ++i){	
		int days = arr[i]-pre;
		temp += cnt*days;
		
//		cout << arr[i] << " : " << cnt << " and " << temp << '\n';
		
		if(temp >= 20){
			ans++;
			cnt = 0;
			temp = 0;	
		}
		cnt++;
		pre = arr[i];
//		cout << " so " << cnt << ' ' << temp << " left and ans = " << ans << '\n';
	}
	
	cout << ans+1 << '\n';
	
	return 0;
}


