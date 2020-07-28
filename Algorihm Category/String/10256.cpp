#include <bits/stdc++.h>

const int MAX = 4;
using namespace std;

int ans;
map<char, int> mp;

struct Trie{
	Trie *child[MAX];
	Trie *fail;
	bool is_end;
	
	Trie(){
		fill(child, child+MAX, nullptr);
		fail = nullptr;
		is_end = false;
	}
	~Trie(){
		for (int i=0;i<MAX;i++){
			if (child[i]) delete child[i];
		}
	}
	
	void insert(string word){
		Trie* node = this;
		for (int i=0;i<word.size();i++){
			int curr = mp[word[i]];
			if (node->child[curr] == nullptr){
				node->child[curr] = new Trie;
			}
			node = node->child[curr];
		}
		node->is_end = true;
	}
};

void construct_aho(Trie* root){
	queue<Trie*> Q;
	root->fail = root;
	Q.push(root);
	while(!Q.empty()){
		Trie* curr = Q.front(); Q.pop();
		
		for (int i=0;i<MAX;i++){
			Trie* next = curr->child[i];
			if (!next) continue;
			
			if (curr == root) next->fail = root;
			else{
				Trie* dest = curr->fail;
				while(dest != root && dest->child[i] == nullptr){
					dest = dest->fail;
				}
				if (dest->child[i] != nullptr){
					dest = dest->child[i];
				}
				next->fail = dest;
			}
			
			if (next->fail->is_end) curr->is_end = true;
			
			Q.push(next);
		}
	}
}

void search_aho(Trie* root, string word){
	Trie* curr = root;
	
	for (int i=0;i<word.size();i++){
		int next = mp[word[i]];
		while(curr != root && curr->child[next] == nullptr){
			curr = curr->fail;
		}
		if (curr->child[next] != nullptr){
			curr = curr->child[next];
		}
		if (curr->is_end) ans++;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	mp['A'] = 0;
	mp['G'] = 1;
	mp['T'] = 2;
	mp['C'] = 3;
	
	int t;
	cin >> t;
	while(t--){
		ans = 0;
		int N, M;
		cin >> N >> M;
		string DNA, mutant;
		cin >> DNA >> mutant;
		Trie* root = new Trie;
		
		
		root->insert(mutant);
		for (int i=0;i<M-1;i++){
			for (int j=i+1;j<M;j++){
				if (i==j) continue;
				string temp = "";
				for (int k=0;k<i;k++) temp += mutant[k];
				for (int k=j;k>=i;k--) temp += mutant[k];
				for (int k=j+1;k<M;k++) temp += mutant[k];
				root->insert(temp);
			}
		}
		
		construct_aho(root);
		
		search_aho(root, DNA);
		cout << ans << endl;
		
		
		delete root;
	}
	
	return 0;
}


