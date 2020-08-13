#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;
	vector<pii> S1;
	vector<pii> S2;
	scanf("%d", &N);
	for (int i=0;i<N;i++){
		int x, y;
		scanf("%d %d", &x, &y);
		S1.push_back({x, y});
		S2.push_back({y, x});
	}
	sort(S1.begin(), S1.end());
	sort(S2.begin(), S2.end());
	
	int P;
	scanf("%d", &P);
	for (int i=0;i<P;i++){
		int curr = 0;
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int pos1 = lower_bound(S1.begin(), S1.end(), make_pair(x1, y1)) - S1.begin();
		int pos2 = upper_bound(S1.begin(), S1.end(), make_pair(x1, y2)) - S1.begin();
		curr += pos2 - pos1;
		
		pos1 = lower_bound(S1.begin(), S1.end(), make_pair(x2, y1)) - S1.begin();
		pos2 = upper_bound(S1.begin(), S1.end(), make_pair(x2, y2)) - S1.begin();
		curr += pos2 - pos1;
		
		pos1 = lower_bound(S2.begin(), S2.end(), make_pair(y1, x1+1)) - S2.begin();
		pos2 = upper_bound(S2.begin(), S2.end(), make_pair(y1, x2-1)) - S2.begin();
		curr += pos2 - pos1;
		
		pos1 = lower_bound(S2.begin(), S2.end(), make_pair(y2, x1+1)) - S2.begin();
		pos2 = upper_bound(S2.begin(), S2.end(), make_pair(y2, x2-1)) - S2.begin();
		curr += pos2 - pos1;
		
		printf("%d\n", curr);
	}
	
	return 0;
}


