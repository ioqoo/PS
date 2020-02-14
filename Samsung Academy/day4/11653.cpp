#include <bits/stdc++.h>
#define MAX 10000005

using namespace std;

bool sieve[MAX];
int N;
vector<int> primes;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d", &N);
	if (N == 1) {
		return 0;
	}
	
	for (int i=2;i<=N;i++){
		if (!sieve[i]){
			sieve[i] = true;
			primes.push_back(i);
			for (int j=2;i*j<=N;j++){
				sieve[i*j] = true;
			}
		}
	}
	
	while(N != 1){
		for (auto p: primes){
			if (N%p == 0){
				N /= p;
				printf("%d\n", p);
				break;
			}
		}
	}

	return 0;
}
