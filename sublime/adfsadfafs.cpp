#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int ss=s.size();
		stack <char> st;
		for(int i=0;i<ss;i++){
			if(s[i]=='(') {
				st.push('(');
				continue;
			}
			if(st.empty()) st.push(')');
			else {
				char a=st.top();
				if(a=='(') st.pop();
				else st.push(')');
			}
		}
		if(st.empty()) cout<<"YES\n";
		else cout<<"NO\n";
	}

}