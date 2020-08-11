#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	vector<int> vt;
	for (int i=0;i<5;i++){
		vt.push_back(i);
	}
	for (auto it = vt.begin();it!=vt.end();it++){
		auto n = *it;
		vt.erase(it);
		if (n == 3) break;
	}
	for (auto n: vt){
		printf("%d\n", n);
	}
	
	
	
	return 0;
}


