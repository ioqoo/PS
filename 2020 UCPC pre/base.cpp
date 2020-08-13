#include <bits/stdc++.h>
const int MAX = 1000005;
using namespace std;

//string dp[MAX];
int N;
string solve(int n){
	if (n == 1) return "#";
	if (n == 2) return "##";
	
	if (__builtin_popcount(n) == 1){
		string ret = "";
		for (int i=0;i<n;i++){
			ret += "#";
		}
		return ret;
	}
	if (n%2){ // odd
		string left = solve(n/2 + 1);
		string right = solve(n/2);
		int L = 1 << (int)ceil(log2(n));
		while(left.size() < L/2){
			left += ".";
		}
		while(right.size() < L/2){
			right += ".";
		}
		return left + right;
	}
	else{
		string left = solve(n/2);
		int L = 1 << (int)ceil(log2(n));
		while(left.size() < L/2){
			left += ".";
		}
		return left + left;
	}
	
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;
//	memset(dp, -1, sizeof(dp));
	
	for (int i=1;i<=N;i++){
		cout << i << " " << solve(i) << endl;
	}
	
	return 0;
}


