#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	scanf("%d", &t);
	while(t--){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if (x > max(y, z)){
			printf("NO\n");
			continue;
		}
		else if (y > max(x, z)){
			printf("NO\n");
			continue;
		}
		else if (z > max(x, y)){
			printf("NO\n");
			continue;
		}
		else{
			int totalmin = min(x, min(y, z));
			int totalmax = max(x, max(y, z));
			printf("YES\n");
			printf("%d %d %d\n", totalmin, totalmin, totalmax);
			continue;
		}
	}
	
	
	return 0;
}


