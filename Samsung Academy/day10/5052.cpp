#include <iostream>

using namespace std;

struct Trie{
	bool is_marked = false;
	Trie* child[10];
	
	Trie(){
		for (int i=0;i<10;i++){
			child[i] = nullptr;
		}
	}
	~Trie(){
		for (int i=0;i<10;i++){
			if (child[i] != nullptr){
				delete child[i];
			}
		}
	}
	
	bool insert(char *s){
		if (is_marked) return false;
		
		if (*s == '\0') {
			is_marked = true;
			
			for (int i=0;i<10;i++){
				if (child[i]) return false;
			}
			return true;
		}
		
		if (child[*s-'0'] == nullptr){
			child[*s-'0'] = new Trie();
		}
		return child[*s-'0'] -> insert(s + 1);
	}
}*root; 

int N;
char phone[12];

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
//	ios_base::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
	
	int T;
	scanf("%d", &T);
	for (int t=0;t<T;t++){
		int N;
		scanf("%d", &N);
		root = new Trie();
		
		bool ans = true;
		for (int i=0;i<N;i++){
			scanf("%s", phone);
			if (ans){
				ans = root->insert(phone);
			}
		}
		delete root;
		
		printf(ans?"YES\n":"NO\n");
		
	}
	
	return 0;
}
