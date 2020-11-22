#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<char, int> mp_op; // +, -, *, /
map<char, int> op_rank;
//set<char> op_list;
string op_list[] = {"+", "-", "*", "/"};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	op_rank['+'] = a;
	op_rank['-'] = b;
	op_rank['*'] = c;
	op_rank['/'] = d;
//	op_list.insert({'+', '-', '*', '/'});

	mp_op['+'] = 0;
	mp_op['-'] = 1;
	mp_op['*'] = 2;
	mp_op['/'] = 3;
	
	string row;
	cin >> row;
	vector<string> tokens;
	ll val = 0;
	bool processing = false;
	for (char c: row){
		if ('0' <= c && c <= '9'){
			val = val*10 + (ll)(c-'0');
			processing = true;
		}
		else{
			if (processing){
				tokens.push_back(to_string(val));
				val = 0;
			}
			processing = false;
			tokens.push_back(op_list[mp_op[c]]);
		}
	}
	if (processing){
		tokens.push_back(to_string(val));
	}
	
	reverse(tokens.begin(), tokens.end());
	
//	for (auto s: tokens){
//		cout << s << endl;
//	}
	
	vector<string> postfix;
	stack<char> st;
	for (auto s: tokens){
		if ('0' <= s[0] && s[0] <= '9'){
			postfix.push_back(s);
			continue;
		}
		else{
			char curr_op = s[0];
			if (st.empty()){
				st.push(curr_op);
				continue;
			}
			while(1){
				char top_op = st.top();
				if (op_rank[top_op] >= op_rank[curr_op]){
					postfix.push_back(op_list[mp_op[top_op]]);
					st.pop();
					if (st.empty()){
						st.push(curr_op);
						break;
					}
				}
				else{
					st.push(curr_op);
					break;
				}
			}
		}
	}
	while(!st.empty()){
		postfix.push_back(op_list[mp_op[st.top()]]);
		st.pop();
	}
//	for (auto p: postfix){
//		cout << p << " ";
//	}
//	cout << endl;
	
	stack<string> S;
	for (auto curr: postfix){
		if ('0' <= curr[0] && curr[0] <= '9'){
			S.push(curr);
//			cout << curr << endl;
			continue;
		}
		else{
			ll A = stoll(S.top());
			S.pop();
			ll B = stoll(S.top());
			S.pop();
			char OP = curr[0];
//			cout << A << " " << OP << " " << B << endl;
			if (OP == '+'){
				S.push(to_string(B+A));
			}
			else if (OP == '-'){
				S.push(to_string(B-A));
			}
			else if (OP == '*'){
				S.push(to_string(B*A));
			}
			else if (OP == '/'){
				S.push(to_string(B/A));
			}
		}
	}
	cout << S.top();
	
	
	return 0;
}


