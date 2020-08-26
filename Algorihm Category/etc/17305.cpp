#include <bits/stdc++.h>
#define ll long long

using namespace std;



int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N, W;
	
	vector<int> three, five;
	scanf("%d %d", &N, &W);
	for (int i=0;i<N;i++){
		int t, s;
		scanf("%d %d", &t, &s);
		if (t == 3) three.push_back(s);
		else five.push_back(s);
	}
	
	sort(three.begin(), three.end(), greater<int>());
	sort(five.begin(), five.end(), greater<int>());
	
	
	
	return 0;
}


