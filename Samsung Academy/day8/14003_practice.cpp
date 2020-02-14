#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
#define MAX 1000005

using namespace std;

int N;
int nums[MAX];
pii track[MAX]; // ( pos , value )
vector<int> IS;
vector<int> ans;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d", &N);
	for (int i=0;i<N;i++){
		scanf("%d", &nums[i]);
	}
	
	IS.push_back(nums[0]);
	track[0] = pii(0, nums[0]);
	
	for (int i=1;i<N;i++){
		int curr = nums[i];
		if (IS.back() < curr){
			track[i] = pii(IS.size(), curr);
			IS.push_back(curr);
		}
		else{
			auto it = lower_bound(IS.begin(), IS.end(), curr);
			*it = curr;
			track[i] = pii(it - IS.begin(), curr);
		}
	}
	
	printf("%d\n", IS.size());
	
	int t = IS.size()-1;
	
	for (int i=N-1;i>=0;i--){
		if (track[i].first == t){
			ans.push_back(track[i].second);
			t--;
		}
	}
	
	reverse(ans.begin(), ans.end());
	for (int n: ans){
		printf("%d ", n);
	}
	
	
}
