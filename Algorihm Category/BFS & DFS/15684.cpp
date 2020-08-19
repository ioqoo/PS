#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

int N, M, H;
bool is_in[33][12];
int ans = 0x3f3f3f3f;
string dest;

bool play(){
	string stat = dest;
	for (int i=1;i<=H;i++){
		for (int j=1;j<N;j++){
			if (is_in[i][j]){
				swap(stat[j-1], stat[j]);
			}
		}
	}
	if (stat == dest) return true;
	return false;
}

void solve(int i, int j, int cnt){
	bool pass = false;
	if (j == N) return;
	if (cnt > 3) return;
	if (is_in[i][j]) pass = true;
	if (j > 1){
		if (is_in[i][j-1]) pass = true;
	}
	if (j < N-1){
		if (is_in[i][j+1]) pass = true;
	}
	
	if (pass){
		if (i==H){
			solve(1, j+1, cnt);
		}
		else{
			solve(i+1, j, cnt);
		}
	}
	else{
		is_in[i][j] = true;
		
		if (play()) ans = min(ans, cnt);
		if (i == H) {
			solve(1, j+1, cnt+1);
			is_in[i][j] = false;
			solve(1, j+1, cnt);
		}
		else{
			solve(i+1, j, cnt+1);
			is_in[i][j] = false;
			solve(i+1, j, cnt);
		}
	}
	
	
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N >> M >> H;
	for (int i=1;i<=N;i++){
		dest += ('0' + i);
	}
//	scanf("%d %d %d", &N, &M, &H);
	for (int i=0;i<M;i++){
		int a, b;
		cin >> a >> b;
//		scanf("%d %d", &a, &b);
		is_in[a][b] = true;
	}	
	
	if (play()) {
		cout << "0";
		return 0;
	}
	
	solve(1, 1, 1);
	
//	for (int i=1;i<=H;i++){
//		for (int j=1;j<N;j++){
//			cout << is_in[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	cout << (ans == 0x3f3f3f3f ? -1 : ans);
	
	return 0;
}


