#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N, K, P, W;
	scanf("%d %d %d %d", &N, &K, &P, &W);
	int ans = 0;
	ans += P / W;
	if (P%W != 0) ans++;
	
	printf("%d\n", ans);
	
	
	return 0;
}


