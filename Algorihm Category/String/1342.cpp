#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
string word;
int cnt;


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> word;
	N = word.size();
	
	sort(word.begin(), word.end());
	
	bool flag = true;
	for (int i=1;i<N;i++){
		if (word[i] == word[i-1]){
			flag = false;
			break;
		}
	}
	if (flag) cnt++;
	
	string origin = word;
	
	next_permutation(word.begin(), word.end());
	while(word != origin){
		bool flag = true;
		for (int i=1;i<N;i++){
			if (word[i] == word[i-1]){
				flag = false;
				break;
			}
		}
		if (flag) cnt++;
		
		next_permutation(word.begin(), word.end());
	}
	
	cout << cnt;
	
	return 0;
}


