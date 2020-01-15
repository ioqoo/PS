// https://www.acmicpc.net/problem/18229

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int arr[105][105];
int dist[105];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

	scanf("%d %d %d", &N, &M, &K);
	for (int i=0;i<N;++i){
		for (int j=0;j<M;++j){
			scanf("%d", &arr[i][j]);
		}
	}
	for (int j=0;j<M;++j){
		for (int i=0;i<N;++i){
			dist[i] += arr[i][j];
			if (dist[i] >= K) {
				printf("%d %d\n", i+1, j+1);
				return 0;
			}
		}
	}
}
