#include <bits/stdc++.h>

using namespace std;

int N, K;
int dp[3005][3005];
int X[3003], Y[3003];
int psum_X[3003], psum_Y[3003];
int last_lose_present_up[3003];


int main(int argc, char** argv){
	setbuf(stdout, NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	int T;
	scanf("%d", &T);
	for (int t=1;t<=T;t++){
		memset(psum_X, 0, sizeof(psum_X));
		memset(psum_Y, 0, sizeof(psum_Y));
		memset(last_lose_present_up, -1, sizeof(last_lose_present_up));
		printf("Case #%d\n", t);
		
		scanf("%d %d", &N, &K);
		for (int i=0;i<=N;i++){
			for (int j=0;j<=N;j++){
				dp[i][j] = -1;
			}
		}
		
		for (int i=1;i<=N;i++){
			scanf("%d", &X[i]);
			psum_X[i] = psum_X[i-1] + X[i];
		}
		
		for (int i=1;i<=N;i++){
			scanf("%d", &Y[i]);
			psum_Y[i] = psum_Y[i-1] + Y[i];
		}
		
		
		dp[0][0] = 1;
		dp[1][0] = dp[0][1] = 0;
		dp[1][1] = 1;
		last_lose_present_up[0] = 1;
		last_lose_present_up[1] = 0;
		
		
		for (int i=0;i<=N;i++){
			int last_lose_present_left = -1;
			for (int j=0;j<=N;j++){
				int &ret = dp[i][j];
				if (ret == 0) last_lose_present_left = j;
				if (ret != -1) continue;
				bool succ = false;
				if (last_lose_present_up[j] != -1){
					// go up
					int curr_pos = last_lose_present_up[j];
					if (psum_X[i] - psum_X[curr_pos] <= K){
						succ = true;
					}
				}
				if (!succ){
					if (last_lose_present_left == -1){
						last_lose_present_left = j;
						last_lose_present_up[j] = i;
						ret = 0;
						continue;
					}
					else{
						if (psum_Y[j] - psum_Y[last_lose_present_left] <= K){
							succ = true;
						}
					}
				}	
				if (!succ) {
					ret = 0;
					last_lose_present_left = j;
					last_lose_present_up[j] = i;
				}
				else ret = 1;
			}
		}
		int win = 0, lose = 0;
		for (int i=0;i<=N;i++){
			for (int j=0;j<=N;j++){
				if (dp[i][j]) win++;
				else lose++;
			}
		}
		printf("%d %d\n", win, lose);
		
	}
		
	return 0;
}

