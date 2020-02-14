#include <bits/stdc++.h>
#define MAX 1000005
#define ll long long

using namespace std;

bool sieve[MAX];
vector<int> primes;
int nums[100];
int N;
int prime_cnt[100][1001];

void decomp(int order, int n){
	int curr = n;
	while(curr != 1){
		for (int p: primes){
			if (curr % p == 0) {
				curr /= p;
				prime_cnt[order][p]++;
				break;
			}
		}
	}
	return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

	for (int i=2;i<=1000;i++){
		if (!sieve[i]) {
			sieve[i] = true;
			primes.push_back(i);
			for (int j=2;i*j<=MAX;j++){
				sieve[i*j] = true;
			}
		}
	}
	


	scanf("%d", &N);
	for (int i=0;i<N;i++){
		scanf("%d", &nums[i]);
	}
	
	for (int i=0;i<N;i++){
		decomp(i, nums[i]);
	}
	

	for (int i=0;i<N;i++){
		for (int j=1;j<=10;j++){
			printf("%d ", prime_cnt[i][j]);
		}
		printf("\n");
	}
	printf("\n");

    return 0;
}
