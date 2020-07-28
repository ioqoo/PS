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
		bool chk[55] = {0,};
		int N;
		scanf("%d", &N);
		for (int i=0;i<2*N;i++){
			int curr;
			scanf("%d", &curr);
			if (!chk[curr]) {
				printf("%d ", curr);
				chk[curr] = true;
				continue;
			}
		}
		printf("\n");
	}
	
	
	return 0;
}


