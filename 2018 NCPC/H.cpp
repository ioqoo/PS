#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct home{
	string name;
	int P, C, T, R;
};

//int L, M, P, C, T, R;
//string n[105];

int L, M;
home H[105];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> L >> M;
	cin.ignore();
	
	for (int i=0;i<M;i++){
		string temp;
		int cnt = 0;
		string row;
		getline(cin, row);
		for (char buff: row){
			if (buff == ','){
				if (cnt == 0){
					H[i].name = temp;
					cnt++;
					temp = "";
					continue;
				}
				else if (cnt == 1){
					H[i].P = stoi(temp);
					cnt++;
					temp = "";
					continue;
				}
				else if (cnt == 2){
					H[i].C = stoi(temp);
					cnt++;
					temp = "";
					continue;
				}
				else if (cnt == 3){
					H[i].T = stoi(temp);
					cnt++;
					temp = "";
					continue;
				}
			}
			else{
				temp += buff;
			}
		}
		H[i].R = stoi(temp);
		cnt++;
		temp = "";
	}
//	for (int i=0;i<M;i++){
//		cout << H[i].name << " " << H[i].P << " " << H[i].C << " " << H[i].T << " " << H[i].R << endl;
//	}
	
	int min_P = 1e9+7;
	vector<string> ans;
	for (int i=0;i<M;i++){
		auto curr = H[i];
//		cout << curr.T << " " << curr.R << " " << L << " " << curr.T << " " << curr.C << endl;
		if (((ll)curr.T + (ll)curr.R) * (ll)L <= (ll)curr.T * (ll)curr.C * (ll)10080) {
			if (curr.P < min_P){
				ans.clear();
				ans.push_back(curr.name);
				min_P = curr.P;
			}
			else if (curr.P == min_P){
				ans.push_back(curr.name);
			}
		}
	}
	if (ans.empty()) {
		cout << "no such mower";
	}
	else{
		for (auto s: ans){
			cout << s << endl;
		}
	}
	
	
	return 0;
}


