#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 1<<17;

// 0 : ��� ����
// 1 : ������ ����
int x, goal; 
int st_state;
ll dp[MAX][MAX][2];



//ll make_dp(int b_state, int w_state=0, bool white=false){
//	
//	// 1�� col
//	int temp = 0;
//	bool go = false;
//	for(int i=0; i<4; ++i){
//		if(b_state
//	}
//	
//	
//	
//	
//}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> x;
	st_state |= 4*(x-1);
	int a, b, temp;
	cin >> a >> b;
	
	int c = a|b;
	cout << c << '\n';	
	
	temp = 4*(b-1) + (a-1);	
	goal = 1<<temp;
	
//	cout << make_dp(st_state) << '\n';
	
	return 0;
}


