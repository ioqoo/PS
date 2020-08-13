#include <bits/stdc++.h>
const int MAX = 1005;
using namespace std;

int N;
int preord[MAX];
map<int, int> mp;
vector<int> ans;

void solve(int m, int l, int r){
//	printf("%d %d %d\n", m, l, r);
	if (l > r) return;
	if (l == r){
		ans.push_back(preord[m]);
		return;
	}
	int pos = mp[preord[m]];
	int new_l_1 = l, new_r_1 = pos - 1;
	int new_l_2 = pos + 1, new_r_2 = r;
	
//	printf("%d %d / %d %d\n", new_l_1, new_r_1, new_l_2, new_r_2);
	solve(m+1, new_l_1, new_r_1);
	solve(m+1 + (pos-l), new_l_2, new_r_2);
	ans.push_back(preord[m]);
//	return;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &N);
		fill(preord, preord+N, 0);
		mp.clear();
		ans.clear();
		for (int i=0;i<N;i++){
			scanf("%d", &preord[i]);
		}
		for (int i=0;i<N;i++){
			int temp;
			scanf("%d", &temp);
			mp[temp] = i;
		}
		solve(0, 0, N-1);
		for (int n: ans){
			printf("%d ", n);
		}
		printf("\n");
	}
	
	return 0;
}

