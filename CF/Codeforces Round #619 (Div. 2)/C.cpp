#include <bits/stdc++.h>
#define MAX 100005
#define ll long long

using namespace std;

int T;
int N;


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
	
	scanf("%d", &T);
	for (int t=0;t<T;t++){
		ll n, m;
		scanf("%lld %lld", &n, &m);
		if (m==0LL) {
			printf("0\n");
		}
		else if (m == 1LL){
			if (n%2){
				printf("%lld\n", (n/2 + 1) * (n/2 + 1));
			}
			else{
				printf("%lld\n", (n/2) * (n/2 + 1));
			}
		}
		else if (n == m){
			printf("%lld\n", n*(n+1)/2);
		}
		else if (m == 2LL){
			if (n == 3){
				printf("5\n");
				continue;
			}
			else if (n == 4){
				printf("8\n");
				continue;
			}
			if (n%2){
				printf("%lld\n", (n-2)*3 + ((n-3)/2)*((n-3)/2+1));
			}
			else{
				printf("%lld\n", (n-2)*3 +  ((n-3)/2+1)*((n-3)/2+1));
			}
		}
		else{
			printf("%lld\n", n*(n-1)/2 + m);
		}
	}
	
}
