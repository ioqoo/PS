#include <bits/stdc++.h>
using namespace std;


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
//		memset(str, NULL, sizeof(str));
//		scanf("%s", str);
		string str;
		cin >> str;
		list<char> L;
		auto it = L.begin();
		for (int i=0;i<str.size();i++){
			char curr = str[i];
			if (curr == '<'){
				if (it == L.begin()) continue;
				it--;
			}
			else if (curr == '>'){
				if (it == L.end()) continue;
				it++;
			}
			else if (curr == '-'){
				if (it == L.begin()) continue;
				it--;
				it = L.erase(it);
			}
			else{
				L.insert(it, curr);
//				if (it != L.end()) it++;
			}
//			for (auto iter=L.begin();iter!=L.end();iter++){
//				printf("%c", *iter);
//			}
//			printf("\n");			
		}
		for (auto iter=L.begin();iter!=L.end();iter++){
			cout << *iter;
		}
		cout << "\n";
	}
	
	return 0;
}

