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
#define vll vector<ll>
#define vpii vector<pii>
#define vpdd vector<pdd>
#define fi first
#define se second
#define INF 1000000000000000000LL
#define MAX 987654321
using namespace std;

int sum(vector<int> &tree, int i){
	int ans = 0;
	while(i > 0){
		// printf("%d %d\n", i, tree[i]);
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

void update(vector<int> &tree, int i, int diff){
	while (i < tree.size()){
		tree[i] += diff;
		i += (i & -i);
	}
}

int arr[100001];

int main() {
	int N, K;
	while(scanf("%d", &N)!=EOF){
		scanf("%d", &K);
		memset(arr, 0, sizeof(arr));
		vector<int> minus_tree(N+1);
		vector<int> zero_tree(N+1);
		for (int i=1;i<=N;i++){
			int temp;
			scanf("%d", &temp);
			if (temp>0) arr[i] = 1;
			else if (temp<0) arr[i] = -1;
			else arr[i] = 0;
			if (arr[i] < 0) update(minus_tree, i, 1);
			else if (arr[i] == 0) update(zero_tree, i, 1);
		}

		for (int x=0;x<K;x++){
			char op;
			scanf("\n%c", &op);
			// printf("%c\n", op);
			if (op == 'C') {
				int pos, val;
				scanf("%d %d", &pos, &val);
				if (val>0) val = 1;
				else if (val<0) val = -1;
				else val = 0;
				if (val == 1){
					if (arr[pos] == -1){
						arr[pos] = 1;
						update(minus_tree, pos, -1);
					}
					else if (arr[pos] == 0){
						arr[pos] = 1;
						update(zero_tree, pos, -1);
					}
				}
				else if (val == -1){
					if (arr[pos] == 0) {
						arr[pos] = -1;
						update(minus_tree, pos, 1);
						update(zero_tree, pos, -1);
					}
					else if (arr[pos] == 1){
						arr[pos] = -1;
						update(minus_tree, pos, 1);
					}
				}
				else {
					if (arr[pos] == -1){
						arr[pos] = 0;
						update(minus_tree, pos, -1);
						update(zero_tree, pos, 1);
					}
					else if (arr[pos] == 1){
						arr[pos] = 0;
						update(zero_tree, pos, 1);
					}
				}
			}
			else if (op == 'P'){
				int a, b;
				scanf("%d %d", &a, &b);
				int zero_cnt = sum(zero_tree, b) - sum(zero_tree, a-1);
				int minus_cnt = sum(minus_tree, b) - sum(minus_tree, a-1);
				// printf("%d %d // ", sum(zero_tree, b), sum(zero_tree, a-1));
				if (zero_cnt > 0) printf("0");
				else {
					if (minus_cnt%2) printf("-");
					else printf("+");
				}
			}
		}
		printf("\n");
	}
}

