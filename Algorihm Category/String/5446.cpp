#include <bits/stdc++.h>
const int MAX = 26 + 26 + 10 + 1;

using namespace std;

map<char, int> mp;
int ans;

struct Trie{
	Trie* child[MAX];
	bool is_red; // 이 노드 포함 밑으로 지우면 안 되는 단어의 끝 포함 
	bool is_blue; // 이 노드 포함 밑으로 지워야 하는 단어의 끝 포함 
	bool is_blue_end; // 지워야 하는 단어의 끝
	
	Trie(){
		fill(child, child+MAX, nullptr);
		is_red = false;
		is_blue = false;
		is_blue_end = false;
	} 
	~Trie(){
		for (int i=0;i<MAX;i++){
			if (child[i]) delete child[i];
		}
	}
	
	void insert_blue(string word){
		Trie* node = this;
		for (int i=0;i<word.size();i++){
			int c = mp[word[i]];
			if (node->child[c] == nullptr){
				node->child[c] = new Trie;
			}
			node = node->child[c];
			node->is_blue = true;
		}
		node->is_blue_end = true;
	}
	
	void insert_red(string word){
		Trie* node = this;
		
		for (int i=0;i<word.size();i++){
			int c = mp[word[i]];
			if (node->child[c] == nullptr){
				node->child[c] = new Trie;
			}
			node = node->child[c];
			node->is_red = true;
		}
	}
	
	void solve(bool is_root){
		if (!is_root){
			if (is_red && is_blue && is_blue_end){
				ans++;
			}
			else if (!is_red && is_blue){
				ans++;
				return;
			}
			else if (is_red && !is_blue){
				return;
			}
		}
		for (int i=0;i<MAX;i++){
			if (child[i] == nullptr) continue;
			child[i]->solve(false);
		}
		return;
	}
};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int piv = 0;
	for (int i=0;i<26;i++){
		mp[(char)('A' + i)] = piv++;
	}
	
	for (int i=0;i<26;i++){
		mp[(char)('a' + i)] = piv++;
	}
	
	for (int i=0;i<10;i++){
		mp[(char)('0' + i)] = piv++;
	}
	
	mp['.'] = piv;
	
	int t;
	cin >> t;
	while(t--){
		Trie* root = new Trie;
		
		int N;
		cin >> N;
		for (int i=0;i<N;i++){
			string temp;
			cin >> temp;
			root->insert_blue(temp);
		}
		
		int M;
		cin >> M;
		for (int i=0;i<M;i++){
			string temp;
			cin >> temp;
			root->insert_red(temp);
		}
		
		if (M == 0){
			cout << 1 << "\n";
			delete root;
			continue;
		}
		ans = 0;
		root->solve(true);
		
		cout << ans << "\n";
		delete root;
	}
	
	
	return 0;
}


