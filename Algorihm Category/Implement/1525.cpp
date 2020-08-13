#include <bits/stdc++.h>

using namespace std;

map<string, int> dist;
set<string> visited;
int di[] = {-3, -1, 1, 3};

bool is_out(int i){
	if (i < 0 || i >= 9) return true;
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string ans = "123456780";
	
	string s = "";
	for (int i=0;i<9;i++){	
		string temp;
		cin >> temp;
		s += temp;
	}
	
	queue<string> Q;
	Q.push(s);
	visited.insert(s);
	dist[s] = 0;
	bool succ = false;
	while(!Q.empty()){
		string curr = Q.front(); Q.pop();
//		cout << curr << endl;
//		cout << curr << endl;
		if (curr == ans) {
			succ = true;
			break;
		}
		int curr_dist = dist[curr];
		int pos;
		for (int i=0;i<9;i++){
			if (curr[i] == '0') {
				pos = i;
				break;
			}
		}
		for (int d=0;d<4;d++){
			int ni = pos + di[d];
			if (ni < 0 || ni > 8) continue;
			if (d == 1 && pos % 3 == 0) continue;
			if (d == 2 && pos % 3 == 2) continue;
			string temp = curr;
			swap(temp[pos], temp[ni]);
			if (visited.count(temp)) continue;
			dist[temp] = curr_dist + 1;
			visited.insert(temp);
			Q.push(temp);
		}
	}
	if (succ) cout << dist[ans];
	else cout << -1;
	
	return 0;
}

