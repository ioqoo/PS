#include <bits/stdc++.h>

using namespace std;

unordered_set<string> color;
unordered_set<string> team;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N, M;
	cin >> N >> M;
	for (int i=0;i<N;i++){
		string word;
		cin >> word;
		color.insert(word);
	}
	for (int i=0;i<M;i++){
		string word;
		cin >> word;
		team.insert(word);
	}
	int Q;
	cin >> Q;
	for (int i=0;i<Q;i++){
		string row;
		cin >> row;
		int n = row.size();
		bool succ = false;
		for (int i=1;i<n;i++){
			string left = row.substr(0, i);
			string right = row.substr(i, n-i);
			if (color.count(left) && team.count(right)){
				succ = true;
				break;
			}
		}
		cout << (succ ? "Yes\n" : "No\n");
		
	}
	
	
	return 0;
}

