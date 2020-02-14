#include <iostream>
#include <cstdio>


#define MAX 1030
#define ll long long

using namespace std;

int N, M;
int psum[MAX][MAX];


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
	scanf("%d %d", &N, &M);
	for (int i=1;i<=N;i++){
		for (int j=1;j<=N;j++){
			int temp;
			scanf("%d", &temp);
			psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + temp;
		}
	}

	
	for (int i=0;i<M;i++){
		int i1, j1, i2, j2;
		scanf("%d %d %d %d", &i1, &j1, &i2, &j2);
		int A = psum[i2][j2];
		int B = psum[i2][j1-1];
		int C = psum[i1-1][j2];
		int D = psum[i1-1][j1-1];
		printf("%d\n", A - B - C + D);
	}
	
	return 0;
}
