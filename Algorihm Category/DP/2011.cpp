#include <iostream>
#include <string>
#define ll long long
const ll MOD = 1000000;

using namespace std;

bool is_out(int n){
	if (n < 0 || n >= 26) return true;
	return false;
}

int N;
ll cnt = 1;
ll dp[5005];






int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string row;
	cin >> row;
	N = row.size();
	dp[0] = 1;
	if (N==1) {
		cout << 1 << "\n";
		return 0;
	}
	if (row[0] == '0') {
		cout << 0 << "\n";
		return 0;
	}

	dp[1] = 1 + !(is_out((row[0] - '0') * 10 + (row[1] - '0')));
	
	for (int i=2;i<N;i++){
		bool temp = is_out( (row[i-1] - '0')*10 + (row[i] - '0') );
		if (is_out){
			dp[i] = dp[i-2];
		}
		else dp[i] = (dp[i-2] * dp[i-1])%MOD;
	}
	
	for (int i=0;i<N;i++){
		printf("%d ", dp[i]);
	}
	
	
	return 0;
}
