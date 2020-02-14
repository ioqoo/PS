#include <iostream>
#include <cstdio>


#define MAX 100005
#define ll long long

using namespace std;

int N, M;
int psum[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
	scanf("%d %d", &N, &M);
	for (int i=0;i<N;i++){
		int temp;
		scanf("%d", &temp);
		psum[i+1] = psum[i] + temp;
	}
	
	for (int i=0;i<M;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", psum[b] - psum[a-1]);
	}
	
	return 0;
}
