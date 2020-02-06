#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define piii pair<pair<int, int>, int>
#define pddi pair<pair<double, double>, int>
#define plll pair<pair<ll, ll>, ll>
#define vb vector<bool>
#define vi vector<int>
#define vl vector<ll>
#define vpii vector<pii>
#define vpdd vector<pdd>
#define fi first
#define se second
#define INF 1000000000000000000LL
#define MAX 987654321
using namespace std;

//https://www.acmicpc.net/problem/3653
//아이디어 : 숫자가 n개, 빼서 맨 앞에 두는 횟수가 m -> n+m+1개의 배열 준비
//ind 배열로 k번이 n+m+1 배열에서 ind를 뭘로 가지는지 저장

ll sum(vector<ll> &tree, int i){
	ll ans = 0LL;
	while(i > 0){
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

void update(vector<ll> &tree, int i, int diff){
	while(i < tree.size()){
		tree[i] += diff;
		i += (i & -i);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int x=0;x<T;x++){
		int n, m;
		scanf("%d %d", &n, &m);
		vb check(n+m+1);
		vl f_tree(n+m+1);
		vl ind(n+1);
		for (int i=1;i<=n;i++){
			ind[i] = i+m;
		}
		for (int i=m+1;i<=n+m;i++){
			check[i] = true;
			update(f_tree, i, 1);
		}
		for (int i=0;i<m;i++){
			int temp;
			scanf("%d", &temp);
			printf("%lld ", sum(f_tree, ind[temp]-1) - sum(f_tree, m-i));
			check[ind[temp]] = false;
			check[m-i] = true;
			update(f_tree, ind[temp], -1);
			update(f_tree, m-i, 1);
			ind[temp] = m-i;
		}
		printf("\n");
	}
}

