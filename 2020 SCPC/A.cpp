#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int Answer;

int main(int argc, char** argv){
	
//	freopen("input.txt", "r", stdin);
	
	setbuf(stdout, NULL);
	int T, test_case;
	
	scanf("%d", &T);
	for(test_case = 0; test_case  < T; test_case++){
		
		int N, K;
		scanf("%d %d", &N, &K);
		vector<ll> A(N), B(N);
		for (int i=0;i<N;i++){
			scanf("%lld", &A[i]);
		}
		for (int i=0;i<N;i++){
			scanf("%lld", &B[i]);
		}

		sort(A.begin(), A.end()); // 1 3 6
		sort(B.begin(), B.end()); // 4 3 1
		
		ll ans = 2e9+5;
		ll curr_max = 0;
		for (int i=0;i<K;i++){
			ll curr = A[i] + B[K-1-i];
			curr_max = max(curr_max, curr);
		}
		ans = min(ans, curr_max);
		for (int i=0;i<K;i++){
			ll curr = A[K-1-1] + B[i];
			curr_max = max(curr_max, curr);
		}
		ans = min(ans, curr_max);
		

		printf("Case #%d\n", test_case+1);
		printf("%lld\n", ans);
		
	}

	return 0;
}
