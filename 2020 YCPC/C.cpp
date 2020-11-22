#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

vector<pii> arr;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N, M, S;
	scanf("%d %d %d", &N, &M, &S);
	for (int i=0;i<N;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		arr.push_back({a, a+b});
	}
	sort(arr.begin(), arr.end());
	
	vector<pii> nested;
	int L = arr[0].first, R = arr[0].second;
	for (int i=1;i<N;i++){
		int curr_a = arr[i].first, curr_b = arr[i].second;
		if (curr_a <= R){
			R = max(R, curr_b);
		}
		else {
			nested.push_back({L, R});
			L = curr_a, R = curr_b;
		}
	}
	nested.push_back({L, R});
	
	if (nested[0].first >= M){
		printf("0\n");
		return 0;
	}
	for (int i=0;i<nested.size()-1;i++){
		if (nested[i+1].first - nested[i].second >= M){
			printf("%d\n", nested[i].second);
			return 0;
		}
	}
	if (S - nested.back().second >= M){
		printf("%d\n", nested.back().second);
		return 0;
	}
	printf("-1\n");
	
	return 0;
}


