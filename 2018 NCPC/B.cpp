#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;
	bool ok = true;
	string mum = "mumble";
	for(int i=1; i<=N; ++i){
		string num;
		cin >> num;
		if(num==mum) continue;
		
		int temp = 0;
		
		for(int j=0; j<num.length(); ++j){
			int t = num[j]-'0';
			temp = temp*10 + t;
		}
		
		if(temp!=i){
			ok = false;
			break;
		}
	}
	
	if(ok) cout << "makes sense" << '\n';
	else cout << "something is fishy" << '\n';
	
	return 0;
}


