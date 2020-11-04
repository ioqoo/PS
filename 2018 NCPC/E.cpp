#include <bits/stdc++.h>
#define ALL pos[0], pos[1], pos[2], pos[3], pos[4], pos[5], pos[6], pos[7], pos[8], pos[9]
#define FOR(i, a, b) for(int i=a;i<=b;i++)

using namespace std;

float dp[6][6][6][6][6][6][6][6][6][6];
int N, M, D;
float ans = 0;

bool chk(int a, int b, int c, int d, int e){
	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0) return true;
	return false;
}

float go(int a1, int a2, int a3, int a4, int a5, int b1, int b2, int b3, int b4, int b5, int curr, int remain){
	float &ret = dp[a1][a2][a3][a4][a5][b1][b2][b3][b4][b5];
	if (abs(ret - (-1) > 1e-6)) return ret;
	if (remain == 0){
		if (chk(b1, b2, b3, b4, b5)) return ret = 1;
		return ret = 0;
	}
	ret = 0;
	
	vector<int> pos = {a1, a2, a3, a4, a5, b1, b2, b3, b4, b5};
//	printf("%d %d %d %d %d %d %d %d %d %d\n", ALL);
	for (int i=0;i<10;i++){
		if (pos[i] > 0){
			pos[i]--;
			if (pos[i] == 0) {
				ret += go(ALL, curr-1, remain-1) / curr;
			}
			else{
				ret += go(ALL, curr, remain-1) / curr;
			}
			pos[i]++;
		}
	}
	return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d %d %d", &N, &M, &D);
	vector<int> pos(10);
	
	for (int i=0;i<N;i++){
		scanf("%d", &pos[i]);
	}
	for (int i=0;i<M;i++){
		scanf("%d", &pos[i+5]);
	}
	
	FOR(a, 0, 5) FOR(b, 0, 5) FOR(c, 0, 5) FOR(d, 0, 5) FOR(e, 0, 5) FOR(f, 0, 5) FOR(g, 0, 5) FOR(h, 0, 5) FOR(i, 0, 5) FOR(j, 0, 5) dp[a][b][c][d][e][f][g][h][i][j] = -1;
	
	
	printf("%f\n", go(ALL, N+M, D));
//	printf("%f\n", dp[1][0][0][0][0][1][1][0][0][0]);
	
	return 0;
}


