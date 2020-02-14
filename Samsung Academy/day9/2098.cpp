#include <iostream>
#include <cstdio>
#include <cstring>

#define INF 2100000000
#define ll long long

using namespace std;

int N;
int W[16][16];
int dp[16][1<<16];

int travel(int curr, int visited){
	int &ret = dp[curr][visited];
	if (ret != -1) return ret;
	
	if (visited == (1<<N) - 1){
		if (W[curr][0] != 0){
			return W[curr][0];
		}
		else return INF;
	}
	
	ret = INF;
	
	for (int i=0;i<N;i++){
		if ( (visited & (1<<i) ) || W[curr][i] == 0 ) continue;
		ret = min(ret, travel(i, ( visited | (1<<i) )) + W[curr][i]);
	}
	return ret;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

	scanf("%d", &N);
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			scanf("%d", &W[i][j]);
		}
	}
	
	memset(dp, -1, sizeof(dp));
	printf("%d\n", travel(0, 1));
	
	
	

    return 0;
}
    
