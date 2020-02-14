#include <iostream>
#include <cstdio>

#define MAX 1000005
#define ll long long

using namespace std;

int N;
int num[MAX];
int D1[MAX], D2[MAX];
int ans;
int disc;

int GCD(int a, int b){
	if (a < b) swap(a, b);
	
	if (b==0) return a;
	
	return GCD(b, a%b);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
	scanf("%d", &N);
	for (int i=1;i<=N;i++){
		scanf("%d", &num[i]);
	}
	
	D1[2] = num[1];
	D2[N-1] = num[N];
	for (int i=3;i<=N;i++){
		D1[i] = GCD(D1[i-1], num[i-1]);
	}
	
	for (int i=N-2;i>=1;i--){
		D2[i] = GCD(D2[i+1], num[i+1]);
	}
	
	for (int i=1;i<=N;i++){
		if (i==1) {
			if (num[1]%D2[1] == 0) continue;
			if (ans < D2[1]){
				ans = D2[1];
				disc = num[1];
			}
		}
		else if (i==N) {
			if (num[N]%D1[N] == 0) continue;
			if (ans < D1[N]){
				ans = D1[N];
				disc = num[N];
			}
		}
		else{
			if (num[i] % (GCD(D1[i], D2[i])) == 0) continue;
			if (ans < GCD(D1[i], D2[i])){
				ans = GCD(D1[i], D2[i]);
				disc = num[i];
			}
		}
	}
	
//	for (int i=1;i<=N;i++){
//		printf("%d %d\n", D1[i], D2[i]);
//	}

	if (ans == 0) {
		printf("-1\n");
		return 0;
	}
	printf("%d %d\n", ans, disc);
	
	return 0;
}
