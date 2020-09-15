#include <bits/stdc++.h>
#define ll long long
const int MAX = 200005;
using namespace std;

int N;
int diff[MAX];


int main(){
 	#ifndef ONLINE_JUDGE
 	freopen("input.txt", "r", stdin);
 	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	setbuf(stdout, NULL);
	
	int T;
	scanf("%d", &T);
	for (int t=1;t<=T;t++){
		printf("Case #%d\n", t);
		scanf("%d", &N);
		
		vector<int> A(N);
		vector<int> B(N);
		for (int i=0;i<N;i++){
			scanf("%d", &A[i]);
		}
		for (int i=0;i<N;i++){
			scanf("%d", &B[i]);
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		ll total_diff = 0;
		ll max_diff = 0;
		for (int i=0;i<N;i++){
			diff[i] = abs(A[i] - B[i]);
			max_diff = max(max_diff, (ll)diff[i]);
			total_diff += (ll)diff[i];
		}
		ll reduce_max = 0;
		for (int i=0;i<N;i++){
			int pos = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
			if (pos != i){
				ll Y = (ll)diff[i] + (ll)diff[pos];
				int new_diff_left = abs(A[pos] - B[i]);
				int new_diff_right = abs(B[pos] - A[i]);
				ll X = min((ll)new_diff_left, (ll)new_diff_right);
				reduce_max = max(reduce_max, Y - X);
			}
			if (pos-1 != i && pos-1 >= 0){
				ll Y = (ll)diff[i] + (ll)diff[pos-1];
				int new_diff_left = abs(A[pos-1] - B[i]);
				int new_diff_right = abs(B[pos-1] - A[i]);
				ll X = min((ll)new_diff_left, (ll)new_diff_right);
				reduce_max = max(reduce_max, Y - X);				
			}
		}
		reduce_max = max(reduce_max, max_diff);
		printf("%lld\n", total_diff - reduce_max);
	}
	
	
	
	return 0;
}
