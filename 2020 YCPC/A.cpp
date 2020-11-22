#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, string> A, pair<int, string> B){
	if (A.first == B.first){
		return A.second < B.second;
	}
	return A.first > B.first;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;
	cin >> N;
	vector<pair<int, string>> vt;
	for (int i=0;i<N;i++){
		string name;
		int vote;
		cin >> name >> vote;
		vt.push_back({vote, name});
	}
	sort(vt.begin(), vt.end(), cmp);
	cout << vt.front().second;
	
	return 0;
}


