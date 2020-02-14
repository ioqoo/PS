#include <iostream>
#include <algorithm>

using namespace std;


int N;
int number[505][505];
int dp[505][505];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N ; i++ ) {
		for (int j = 0 ; j < i+1 ; j++ ) {
			scanf("%d", &number[i][j]);
		}
	}
	dp[0][0] = number[0][0];
	for (int i = 1 ; i < N ; i++ ) {
		for (int j = 0 ; j < i+1 ; j++) {
			if (j==0) dp[i][j] = dp[i-1][j] + number[i][j];
			else if (j==i) dp[i][j] = dp[i-1][j-1] + number[i][j];
			else dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + number[i][j];
		}
	}
	printf("%d\n", *max_element(dp[N-1], dp[N-1]+N));
}
