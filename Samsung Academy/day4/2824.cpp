#include <bits/stdc++.h>
#define MAX 40005
#define ll long long
#define MOD 1000000000LL

using namespace std;

bool sieve[MAX]; 
vector<int> primes;
map<ll, ll> Aprimes;
map<ll, ll> Bprimes;
int N, M;
ll A[1005], B[1005];

void decomp(map<ll, ll> &arr, ll n){
	ll curr = n;
	
	for (auto p: primes){
		if (curr % p == 0) {
//			cout << p << endl;
			arr[p]++;
			decomp(arr, curr/p);
			return;
		}
	}
	if (n != 1LL) arr[n]++;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	

	
	for (int i=2;i<=MAX;i++){
		if (!sieve[i]){
			sieve[i] = true;
			primes.push_back(i);
			for (int j=2;i*j<=MAX;j++){
				sieve[i*j] = true;
			}
		}
	}
	
	scanf("%d", &N);
	for (int i=0;i<N;i++){
		ll temp;
		scanf("%lld", &temp);
		decomp(Aprimes, temp);
	}
	
	scanf("%d", &M);
	for (int i=0;i<M;i++){
		ll temp;
		scanf("%lld", &temp);
		decomp(Bprimes, temp);
	}
		
	
	ll GCD = 1LL;
	bool ov = false;
	
	for (auto iter: Aprimes){
		ll curr = iter.first;
		if (!Bprimes.count(curr)) continue;
		ll commoncnt = min(Aprimes[curr], Bprimes[curr]);
		for (int n=0;n<commoncnt;n++){
			GCD *= curr;
			if (GCD > MOD) {
				GCD %= MOD;
				ov = true;
			}
		}
	}
	
	
	string answer = to_string(GCD);
	if (ov){
		while(answer.size() < 9){
			answer = '0' + answer;
		}
		cout << answer;
	}
	else cout << answer;
	

	return 0;
}
