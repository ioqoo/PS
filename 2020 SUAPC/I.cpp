#include <bits/stdc++.h>
#define ll long long
const ll PN = 100005;
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
 
// 오일러 파이 함수 = v 와 서로소인 수의 갯수 return
 
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
	
	int N;
	scanf("%d", &N);
	primechk();
	for (auto p: prime){
		if (p * euler(p) == N){
			printf("%lld\n", p);
			return 0;
		}
	}
//	for (ll i=1;i<=PN;i++){
//		if (i * e == N) {
//			printf("%lld\n", i);
//			return 0;
//		}
//	}
	printf("-1\n");
	
	
	
	return 0;
}

