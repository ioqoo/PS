#include <bits/stdc++.h>
#define pii pair<int, int>
const int MAX = 500005;

using namespace std;

int chk[MAX];
bool inPQ[MAX];
bool used[MAX];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;
	scanf("%d", &N);
	vector<int> arr(N);
	for (int i=0;i<N-2;i++){
		scanf("%d", &arr[i]);
		chk[arr[i]]++;
	}
	
	priority_queue<int> PQ;
	
	for (int i=1;i<=N;i++){
		if (chk[i] == 0) {
			PQ.push(i);
			inPQ[i] = true;
		}
	}
	
	vector<pii> ans;
	
	for (int i=0;i<N-2;i++){
		int u = arr[i];
		int v = PQ.top();
		used[u] = true; used[v] = true;
//		printf("new : %d / old : %d\n", u, v);
		if (u == v) {
			printf("-1\n");
			return 0;
		}
		ans.push_back({min(u, v), max(u, v)});
		if (--chk[u] > 0){
			if (!PQ.empty()) PQ.pop();
		}
		else{
			if (!PQ.empty()) PQ.pop();
			PQ.push(u);
		}
	}
	vector<int> notused;
	for (int i=1;i<=N;i++){
//		printf("%d ", used[i]);
		if (!used[i]) {
			notused.push_back(i);
		}
	}
	int notusednum = 0;
	if (notused.size() > 1){
		printf("-1\n");
		return 0;
	}
	else {
		notusednum = notused[0];
	}
	ans.push_back({min(notusednum, arr[N-3]), max(notusednum, arr[N-3])});
	sort(ans.begin(), ans.end());
	
	for (auto p: ans){
		printf("%d %d\n", p.first, p.second);
	}
	
	
	return 0;
}


