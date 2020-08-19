#include <bits/stdc++.h>
#define ll long long
#define PN 100005
using namespace std;

bool isprime[PN+5];
vector<long long> prime;
void primechk(){
    for(int i=2;i<=PN;i++) isprime[i] = true;
    for(long long i=2;i<=PN;i++)
        if(isprime[i]){
            prime.push_back(i);
            for(long long j=i*i;j<=PN;j+=i)
                isprime[j] = false;
        }
}

long long euler(long long v){
    long long ret=1;
    for(auto now: prime){
        long long p=1;
        while(v%now==0){
            v/=now;
            p*=now;
        }
        if(p!=0){
            ret*=(p-(p/now));
        }
    }
    if(v!=1) ret*=(v-1);
    return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll N;
	scanf("%lld", &N);
	primechk();
	vector<ll> divisors;
	for (ll i=1;i*i<=N;i++){
		if (N%i==0) divisors.push_back(i);
	}
	vector<ll> divisors_2;
	for (auto n: divisors){
		if (n*n == N) continue;
		divisors_2.push_back(N/n);
	}
	sort(divisors_2.begin(), divisors_2.end());
	divisors.insert(divisors.end(), divisors_2.begin(), divisors_2.end());
	
//	for (auto p: divisors){
//		printf("%lld\n", p);
//	}
//	printf("%d\n", euler(8));
	for (auto p: divisors){
//		printf("%lld\n", p);
		if ((p * euler(p)) == N){
			printf("%lld\n", p);
			return 0;
		}
	}
	printf("-1\n");
	
	
	
	return 0;
}

