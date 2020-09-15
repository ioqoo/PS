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

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	setbuf(stdout, NULL);
	
	int T;
	cin >> T;
	for (int t=1;t<=T;t++){
		cout << "Case #" << t << "\n";
		cin >> N;
		if (N > 5000) {
			cout << "0\n";
			continue;
		}
		
		vector<int> A(N);
		vector<int> B(N);
		for (int i=0;i<N;i++){
			int temp;
			cin >> temp;
			A[i] = temp;
		}
		for (int i=0;i<N;i++){
			int temp;
			cin >> temp;
			B[i] = temp;
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());


		ll total_diff = 0;
		ll max_diff = 0;
		for (int i=0;i<N;i++){
			diff[i] = abs(A[i] - B[i]);
			max_diff = max(max_diff, (ll)diff[i]);
			total_diff += diff[i];
		}
		ll reduce_max = 0;
		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++){
				if (i==j) continue;
				reduce_max = max(reduce_max, (ll)(diff[i] + diff[j]) - min((ll)abs(A[i] - B[j]), (ll)abs(A[j] - B[i])));
			}
		}
		reduce_max = max(reduce_max, max_diff);		
		cout << total_diff - reduce_max << "\n";
		
	}
	
	
	
	return 0;
}
