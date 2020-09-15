#include <bits/stdc++.h>
using namespace std;

string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int ALPHA_size = 26;
bool chk[26];
set<string> S;

void prepro(vector<string> orders){
	for (string s: orders){
		for (char c: s){
			if (!chk[c-'a']){
				chk[c-'a'] = true;
				ALPHA += c;
			}
		}
	}
	ALPHA_size = ALPHA.size();
}

void brute(vector<string> orders, int size){
	int N = orders.size();
	vector<int> perm;
	for (int i=0;i<size;i++){
		perm.push_back(1);
	}
	for (int i=size;i<ALPHA_size;i++){
		perm.push_back(0);
	}
	vector<int> origin = perm;
	set<string> temp_set;
	int max_cnt = 2;
	
	while(1){
		string temp = "";
		for (int i=0;i<ALPHA_size;i++){
			if (perm[i] == 1){
				temp += ALPHA[i];
			}
		}
//		cout << temp << endl;
		int curr_cnt = 0;
		for (string s: orders){
			bool is_in = true;
			for (char c: temp){
				bool find = false;
				for (char d: s){
					if (c == d){
						find = true;
						break;
					}
				}
				if (!find) {
					is_in = false;
					break;
				}
			}
			if (is_in) curr_cnt++;
		}
//		cout << curr_cnt << endl;
		
		if (curr_cnt > max_cnt){
			max_cnt = curr_cnt;
			temp_set.clear();
			temp_set.insert(temp);
		}
		else if (curr_cnt == max_cnt){
			temp_set.insert(temp);
		}
		
		next_permutation(perm.begin(), perm.end());
		if (perm == origin) break;
	}
	
	for (string s: temp_set){
		S.insert(s);
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
//    prepro(orders);
    for (int n: course){
    	brute(orders, n);
	}
	for (string s: S){	
		answer.push_back(s);
	}
    
    return answer;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<string> A = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
	vector<int> B = {2, 3, 5};
	vector<string> C = solution(A, B);
	for (auto s: C){
		cout << s << endl;
	}
	
	return 0;
}

