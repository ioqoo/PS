#include <bits/stdc++.h>
using namespace std;
typedef pair<string, string> pii;

int N;
string total;
vector<pii> arr;
set<string> candidate, Yes, No;
vector<string> ans;

string PL(string a, string b){	
	string ret = "";
	stack<char> S1, S2, S;
	
	for(int i=0; i<a.length(); ++i) S1.push(a[i]);
	for(int i=0; i<b.length(); ++i) S2.push(b[i]);
	
	int pre = 0;
	while(!S1.empty() || !S2.empty()){
		
		int temp1 = 0;
		if(!S1.empty()){
			temp1 = S1.top()-'0';
			S1.pop();
		}
		int temp2 = 0;
		if(!S2.empty()){
			temp2 = S2.top()-'0';
			S2.pop();
		}
		
		temp1 += temp2;
		temp1 += pre;
		
		pre = temp1/10;
		temp1 %= 10;
		S.push(temp1+'0');
	}
	while(!S.empty()){
		ret += S.top();
		S.pop();		
	}
	
	return ret;
}
string MI(string a, string b){	
	string ret = "";
	stack<char> S1, S2, S;
	
	for(int i=0; i<a.length(); ++i) S1.push(a[i]);
	for(int i=0; i<b.length(); ++i) S2.push(b[i]);
	
	int pre = 0;
	while(!S1.empty() || !S2.empty()){
		
		int temp1 = 0;
		if(!S1.empty()){
			temp1 = S1.top()-'0';
			S1.pop();
		}
		int temp2 = 0;
		if(!S2.empty()){
			temp2 = S2.top()-'0';
			S2.pop();
		}
		
		if(pre) temp1--;
		pre = 0;
		if(temp1 < temp2){
			temp1 += 10;
			pre = 1;
		}
		
		temp1 -= temp2;
		S.push(temp1+'0');
	}
	bool start = false;
	while(!S.empty()){
		if(S.top()=='0' && !start){
			S.pop();
			continue;
		}
		start = true;
		ret += S.top();
		S.pop();		
	}
	
	if(ret.empty()) ret = "0";
	return ret;
}

bool isBig(string a, string b){
	if(a.length() > b.length()) return true;
	for(int i=0; i<a.length(); ++i){
		if(a[i] > b[i]) return true;
		else if(a[i] < b[i]) return false;
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N >> total;
	for(int i=0; i<N; ++i){
		
	}
	
	
	return 0;
}


