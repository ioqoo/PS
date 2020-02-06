#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> f_tree(1000011);
int A[500005];
int where[1000005];
int B[1000005];

int sum(vector<int> &tree, int i){
	int ans = 0;
	while(i>0){
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

void update(vector<int> &tree, int i, int diff){
	while(i<tree.size()){
		tree[i] += diff;
		i += (i & -i);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE

	int n;
	scanf("%d", &n);
	for (int i=1;i<=n;i++){
		int temp;
		scanf("%d", &temp);
		A[i] = temp;
	}
	for (int i=1;i<=n;i++){
		int temp;
		scanf("%d", &temp);
		B[i] = temp;
		where[temp] = i;
	}
	ll ans = 0LL;
	for (int i=1;i<=n;i++){
		int curr = A[i];
		int down_ind = where[curr];
		//printf("%d %d\n", curr, down_ind);
		ans += sum(f_tree, n) - sum(f_tree, down_ind);
		update(f_tree, down_ind, 1);
	}
	printf("%lld\n", ans);
}
