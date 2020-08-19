#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> vt;
	vt.push_back(1);
	
	next_permutation(vt.begin(), vt.end());
	
	return 0;
}


