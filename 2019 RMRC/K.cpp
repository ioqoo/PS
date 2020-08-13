#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	vector<int> ans(n+1);
	scanf("%d", &n);
	ans[1] = 1;
	for (int i=2;i<=n;i++){
		int temp;
		scanf("%d", &temp);
		ans[temp+2] = i;
	}
	for (int i=1;i<=n;i++){
		printf("%d ", ans[i]);
	}
	
	
	return 0;
}

