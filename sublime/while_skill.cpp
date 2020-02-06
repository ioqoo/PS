#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

ll n,m,k;
ll p[100010];
int now = 1;
int ans;
int sum;

//http://codeforces.com/contest/1191/problem/C

int main(){
	scanf("%lld %lld %lld", &n, &m, &k);
	for (int i=1;i<=m;i++) {
		scanf("%lld", &p[i]);
	}
	while(now<=m){
		ll pos = ((p[now]-sum-1)/k + 1) * k + sum;
		while(now<=m && p[now]<=pos){
			sum++;
			now++;
		}
		ans++;
	}
	printf("%d", ans);

}