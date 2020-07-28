#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	vector<int> vt;
	int n;
	scanf("%d", &n);
	for (int i=0;i<n;i++){
		int temp;
		scanf("%d", &temp);
		vt.push_back(temp);
	}
	
	while(next_permutation(vt.begin(), vt.end())){
		for (int n: vt){
			printf("%d ", n);
		}
		printf("\n");
	}
	
	
	return 0;
}


