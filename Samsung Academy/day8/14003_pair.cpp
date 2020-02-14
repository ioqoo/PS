#include <bits/stdc++.h>

#define MAX 1000003
#define INF -1000000999
#define pii pair<int, int>

using namespace std;

int N;
pii nums[MAX];
vector<pii> LIS;
vector<int> ans;
int p[MAX];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d", &N);
	for (int i=0;i<N;i++){
		int temp;
		scanf("%d", &temp);
		nums[i] = pii(temp, i);
	}
	
	memset(p, -1, sizeof(p));
	
	LIS.push_back(pii(nums[0].first, -1));
	
	for (int i=1;i<N;i++){
		auto pp = nums[i];
		if (LIS.back().first < pp.first){
			p[pp.second] = LIS.back().second;
			LIS.push_back(pp);
		}
		else{
			auto it = lower_bound(LIS.begin(), LIS.end(), pp);
			p[pp.second] = (it-1)->second;
			*it = pp;
		}
	}
	
	for (int i=LIS.back().second; i>=0; i=p[i]){
		ans.push_back(nums[i].first);
	}	
	reverse(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int n: ans){
		printf("%d ", n);
	}
	
	
	return 0;
}
