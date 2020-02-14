#include <bits/stdc++.h>

#define MAX 1003
#define pii pair<int, int>

using namespace std;

int N;
int nums[MAX];
vector<int> LIS;
vector<int> ans;
vector<pii> real_ans;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d", &N);
	for (int i=0;i<N;i++){
		int temp;
		scanf("%d", &temp);
		nums[i] = temp;
	}
	
	real_ans.push_back(pii(0, nums[0]));
	LIS.push_back(nums[0]);
	
	for (int i=1;i<N;i++){
		int curr = nums[i];
		if (LIS.back() < curr){
			real_ans.push_back(pii(LIS.size(), curr));
			LIS.push_back(curr);
		}
		else{
			auto it = lower_bound(LIS.begin(), LIS.end(), curr);
			*it = curr;
			real_ans.push_back(pii(it-LIS.begin(), curr));
		}
		
//		printf("LIS :");
//		for (auto n: LIS){
//			printf("%d ", n);
//		}
//		printf("\n");
//		for (auto p: real_ans){
//			printf("%d %d\n", p.first, p.second);
//		}		
//		printf("=========\n");
	}
	
	stack<int> st;
	int t = LIS.size()-1;
	printf("%d\n", t+1);
	
	for (auto it=real_ans.rbegin();it!=real_ans.rend();it++){
		if (t == (*it).first){
			st.push((*it).second);
			t--;
		}
	}
	
	while(!st.empty()){
		printf("%d ", st.top());
		st.pop();
	}
	
	
	
	return 0;
}
