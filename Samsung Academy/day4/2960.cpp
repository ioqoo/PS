#include <bits/stdc++.h>
#define MAX 1005

using namespace std;

bool sieve[MAX]; // true : prime
int N, K;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d %d", &N, &K);
	
	int cnt = 0;
	
	for (int i=2;i<=N;i++){
		if (!sieve[i]){
			sieve[i] = true;
			cnt++;
			if (cnt == K){
				printf("%d\n", i);
				return 0;
			}
			for (int j=2;i*j<=N;j++){
				if (!sieve[i*j]){
					cnt++;
					sieve[i*j] = true;
					if (cnt == K){
						printf("%d\n", i*j);
						return 0;
					}					
				}

			}
		}
	}
			

	return 0;
}
