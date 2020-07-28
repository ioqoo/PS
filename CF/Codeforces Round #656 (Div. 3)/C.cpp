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
		int N;
		scanf("%d", &N);
		vector<int> arr;
		for (int i=0;i<N;i++){
			int temp;
			scanf("%d", &temp);
			arr.push_back(temp);
		}
		if (N == 1){
			printf("0\n");
			continue;
		}
		
		int pos = -1;
		for (int i=N-1;i>=1;i--){
			int curr = arr[i];
			int left = arr[i-1];
			if (left < curr){
				pos = i-1;
				break;
			}
		}
		if (pos == -1) {
			printf("0\n");
			continue;
		}
		int pos2 = -1;
		for (int i=pos;i>=1;i--){
			int curr = arr[i];
			int left = arr[i-1];
			if (left > curr){
				pos2 = i-1;
				break;
			}
		}
		if (pos2 == -1){
			printf("0\n");
			continue;
		}
		printf("%d\n", (pos2+1));
		
	}
	
	
	return 0;
}


