#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pdd pair<double, double>
#define piii pair<pair<int, int>, int>
#define pddi pair<pair<double, double>, int>
#define plll pair<pair<long long, long long>, long long>
#define vb vector<bool>
#define vi vector<int>
#define vll vector<long long>
#define vpii vector<pii>
#define vpdd vector<pdd>
#define INF 1000000000000000000LL
#define MAX 1234567890
using namespace std;

//http://codeforces.com/gym/101915/problem/J

int p[1000];
pll left_right[1000];
plll holes[1000];

int find(int node){
	if (p[node]==-1) return node;
	p[node] = find(p[node]);
	return p[node];
}

void merge(int node1, int node2){
	int root1 = find(node1);
	int root2 = find(node2);
	if (root1 == root2) return;
	p[root1] = root2;
}

ll dist(pll a, pll b){
	ll a_x = a.first;
	ll a_y = a.second;
	ll b_x = b.first;
	ll b_y = b.second;
	return (b_x - a_x)*(b_x - a_x) + (b_y - a_y)*(b_y - a_y);
}

int main(){
	int T;
	scanf("%d", &T);
	for (int x=0;x<T;x++){
		int N;
		ll W, L;
		int ans = 0;
		scanf("%d %lld %lld", &N, &W, &L);
		for (int i=0;i<N;i++){
			left_right[i] = pll(INF, -1LL);
		}
		fill(p, p+N, -1);
		for (int i=0;i<N;i++){
			ll x, y, r;
			scanf("%lld %lld %lld", &x, &y, &r);
			holes[i] = plll(pll(x, y), r);
		}
		for (int i=0;i<N;i++){
			for (int j=i+1;j<N;j++){
				if (dist(holes[i].first, holes[j].first) <= (holes[i].second + holes[j].second)*(holes[i].second + holes[j].second)){
					merge(i, j);
				}
			}
		}
		for (int i=0;i<N;i++){
			left_right[find(i)].first = min(left_right[find(i)].first, holes[i].first.first - holes[i].second);
			left_right[find(i)].second = max(left_right[find(i)].second, holes[i].first.first + holes[i].second);
		}
		for (int i=0;i<N;i++){
			if (left_right[i].first <= 0 && left_right[i].second >= W){
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}
