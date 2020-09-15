#include <bits/stdc++.h>

using namespace std;

map<set<string>, vector<int>> mp;
vector<vector<string>> keylist = {{"java", "python", "cpp"}, {"backend", "frontend"}, {"junior", "senior"}, {"pizza", "chicken"}};
set<string> Key;
vector<set<string>> KK;

void make_key(int pos){
	if (pos == 4) {
		mp[Key] = {};
		return;
	}
	
	for (auto s: keylist[pos]){
		Key.insert(s);
		make_key(pos+1);
		Key.erase(s);
	}
	make_key(pos+1);
}



vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    int N = info.size();
    
    make_key(0);
    
    for (auto it=mp.begin();it!=mp.end();it++){
    	KK.push_back(it->first);
	}
	
	for (auto q: info){
		string buff = "";
		set<string> curr_key;
		int X;
		for (auto c: q){
			if (c == ' '){
				if (buff != "and" && buff != "-"){
					curr_key.insert(buff);
				}
//				cout << buff << " ";
				buff = "";
				continue;
			}
			buff += c;
		}
		X = stoi(buff);
//		cout << X << endl;

		for (auto it=mp.begin();it!=mp.end();it++){
			auto currS = it->first;
			bool chk = true;
			for (auto k: currS){
				if (!curr_key.count(k)) {
					chk = false;
					break;
				}
			}
			if (chk){
				(it->second).push_back(X);	
//				for (int n: it.second){
//					cout << n << " ";
//				}
//				cout << endl;
			}
		}
	}
	
	for (auto s: KK){
		sort(mp[s].begin(), mp[s].end());
	}

	
//	for (auto s: mp[{"chicken"}]){
//		cout << s << endl;
//	}
	
//	for (auto it: mp){
//		for (auto it2: it.first){
//			cout << it2 << " ";
//		}
//		cout << endl;
//		for (auto n: it.second){
//			cout << n << " ";
//		}
//		cout << endl;
//	}
	
	for (auto q: query){
		string buff = "";
		set<string> curr_key;
		int X;
		for (auto c: q){
			if (c == ' '){
				if (buff != "and" && buff != "-"){
					curr_key.insert(buff);
				}
				buff = "";
				continue;
			}
			buff += c;
		}
		X = stoi(buff);
//		for (auto n: mp[curr_key]){
//			cout << n << " ";
//		}
//		cout << endl;
//		sort(mp[curr_key].begin(), mp[curr_key].end());
//		for (int n: mp[curr_key]){
//			cout << n << " ";
//		}
//		cout << endl;
		int n = mp[curr_key].size();
		int pos = lower_bound(mp[curr_key].begin(), mp[curr_key].end(), X) - mp[curr_key].begin();
		
		answer.push_back(n - pos);		
	}
    
    return answer;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
	vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
	vector<int> ans = solution(info, query);
	for (int n: ans){
		cout << n << endl;
	}
	
	return 0;
}

