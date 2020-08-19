#include <bits/stdc++.h>
const int MAX = 100005;
using namespace std;

struct seg{
	int a, b, num;
	
	bool operator < (seg P){
		if (a == P.a) return b > P.b;
		return a < P.a;
	}
};

struct cmp{
	bool operator () (seg A, seg B){
		if (A.a == B.a) return A.b > B.b;
		return A.a < B.a;
	}
};

bool LDScmp(int a, int b){
	return a >= b;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;
	scanf("%d", &N);
	vector<seg> arr;
	for (int i=0;i<N;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		arr.push_back({a, b, i});
	}
	
	sort(arr.begin(), arr.end());
	
	vector<int> LDS;
	vector<int> P(N);
	for (int i=0;i<N;i++){
		int r = arr[i].b;
		if (LDS.empty()) {
			LDS.push_back(r);
			continue;
		}
		auto pos = lower_bound(LDS.begin(), LDS.end(), r, LDScmp);
		if (pos == LDS.end()) {
			P[i] = LDS.size();
			LDS.push_back(r);
		}
		else{
			*pos = r;
			P[i] = pos - LDS.begin();
		}
	}
	printf("%d\n", LDS.size());
	
	vector<seg> ans;
	int t = LDS.size() - 1;
	for (int i=N-1;i>=0;i--){
		if (P[i] == t){
			t--;
			ans.push_back(arr[i]);
//			printf("%d %d\n", arr[i].a, arr[i].b);
		}
	}
	reverse(ans.begin(), ans.end());
	for (auto p: ans){
		printf("%d %d\n", p.a, p.b);
	}
	
	
	
	
	
	return 0;
}


