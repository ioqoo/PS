#include <bits/stdc++.h>

using namespace std;

set<int> visited;

int next_num(int x){
	int ret = 0;
	while(x){
		int temp = x%10;
		ret += temp*temp;
		x/=10;
	}
	return ret;
}

bool happy(int x){
	if(visited.count(x)) return false;
	visited.insert(x);
	if(x==1) return true;
	
	return happy(next_num(x));
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int x;
	cin >> x;
	
	if(happy(x)) cout << "HAPPY" << '\n';
	else cout << "UNHAPPY" << '\n';
	
	
	return 0;
}


