#include <bits/stdc++.h>
#define MAX 100005
#define INF 1987654321

using namespace std;

int T;
int N;
int nums[MAX];


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
	
	scanf("%d", &T);
	for (int t=0;t<T;t++){
		scanf("%d", &N);
		for (int i=0;i<N;i++){
			scanf("%d", &nums[i]);
		}
		int curr_max = -1;
		for (int i=0;i<N-1;i++){
			int a = nums[i], b = nums[i+1];
			if (a!=-1 && b!=-1){
				curr_max = max(curr_max, abs(a-b));
			}
		}
		vector<int> adj;
		for (int i=0;i<N;i++){
			int curr = nums[i];
			if (curr != -1) continue;
			if (i==0) {
				if (nums[i+1] != -1){
					adj.push_back(nums[i+1]);
				}
			}
			else if (i == N-1){
				if (nums[i-1] != -1){
					adj.push_back(nums[i-1]);
				}
			}
			else{
				if (nums[i+1] != -1){
					adj.push_back(nums[i+1]);
				}
				if (nums[i-1] != -1){
					adj.push_back(nums[i-1]);
				}
			}
		}
		if (adj.empty()){

			printf("0 0\n");
			continue;
		}
		
		sort(adj.begin(), adj.end());
		int M = adj.back(), m = adj.front();
		int mid = (M+m)/2;
		int ans_m = M - mid;
		int k = mid;
//		if (curr_max == -1){
//			printf("%d %d\n", 
//		}
		if (curr_max != -1){
			if (curr_max > ans_m){
				ans_m = curr_max;
			}
		}
		printf("%d %d\n", ans_m, k);
		
		
	}
	
}
