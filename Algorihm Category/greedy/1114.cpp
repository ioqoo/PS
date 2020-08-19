#include <bits/stdc++.h>
using namespace std;

int L, K, C;
vector<int> P;
vector<int> pos;

bool cut(int curr_max_length){
	int remain_cut_cnt = C;
	int curr_length = 0;
	for (int i=K;i>=0;i--){
		if (pos[i] > curr_max_length) return false;
		curr_length += pos[i];
		if (curr_length > curr_max_length){
			remain_cut_cnt--;
			curr_length = pos[i];
		}
	}
	if (remain_cut_cnt < 0) return false;
	return true;
}

int make_ans(int max_length){
	int remain_cut_cnt = C;
	int curr_length = 0;
	int ans = 1e9+1;
	for (int i=K;i>=0;i--){
		curr_length += pos[i];
		if (curr_length > max_length){
			remain_cut_cnt--;
			ans = min(ans, P[i]);
			curr_length = pos[i];
		}
	}
	if (remain_cut_cnt > 0){
		return P[0];
	}
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d %d %d", &L, &K, &C);
	for (int i=0;i<K;i++){
		int temp;
		scanf("%d", &temp);
		P.push_back(temp);
	}
	sort(P.begin(), P.end());
	for (int i=0;i<=K;i++){
		if (i==0) pos.push_back(P[i]);
		else if (i==K) pos.push_back(L - P[i-1]);
		else pos.push_back(P[i] - P[i-1]);
	}

	int lo = 0, hi = 1e9;
	int ans = hi+1;
	while(lo <= hi){
		int mid = (lo + hi) / 2;
		bool result = cut(mid);
		if (result) {
			ans = min(ans, mid);
			hi = mid-1;
		}
		else lo = mid+1;
	}
	
	printf("%d %d\n", ans, make_ans(ans));
	
	return 0;
}


