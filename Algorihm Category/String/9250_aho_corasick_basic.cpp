#include <bits/stdc++.h>

const int MAX = 26;
using namespace std;

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
		for (int i=0;i<26;i++){
			if (child[i]) delete child[i];
		}
	}
	void insert(string word){
		Trie* node = this;
		for (int i=0;i<word.size();i++){
			char c = word[i];
			if (node->child[c-'a'] == nullptr) {
				node->child[c-'a'] = new Trie;
			}
			node = node->child[c-'a'];
		}
		node->is_end = true;
	}
};

void construct_aho(Trie *root){
	queue<Trie*> Q;
	Q.push(root);
	root->fail = root;
	while(!Q.empty()){
		Trie *curr = Q.front(); Q.pop();
		
		for (int i=0;i<MAX;i++){
			Trie *next = curr->child[i];
			if (!next) continue;
			
			if (curr == root) next->fail = root;
			else{
				Trie *dest = curr->fail;
				// KMP : while(j>0 && H[i] != N[j]), H : hay, N : niddle 
				while(dest != root && !dest->child[i]){
					dest = dest->fail;
				}
				// KMP : if (H[i] == N[j]) 
				if (dest->child[i]){
					dest = dest->child[i];
				}
				// fail(x) = y => fail(xz) = yz
				next->fail = dest;
			}
			
			if (next->fail->is_end) next->is_end = true;
			
			Q.push(next);
		}	
	}
}

bool search_aho(Trie* root, string word){
	Trie* curr = root;
	
	for (int i=0;i<word.size();i++){
		int next = word[i] - 'a';
		while(curr != root && curr->child[next] == nullptr){
			curr = curr->fail;
		}
		if (curr->child[next] != nullptr){
			curr = curr->child[next];
		}
		if (curr->is_end) return true;
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;
	scanf("%d", &N);
	Trie *root = new Trie;
	char word[10005];
	for (int i=0;i<N;i++){
		scanf("%s", word);
		root->insert(word);
	}
	
	construct_aho(root);
	
	int M;
	scanf("%d", &M);
	for (int i=0;i<M;i++){
		scanf("%s", word);
		printf(search_aho(root, word) ? "YES\n" : "NO\n");
	}
	
	delete root;
	
	return 0;
}


