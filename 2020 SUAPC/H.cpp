#include <bits/stdc++.h>

const int MAX = 26;
using namespace std;

struct Trie{
	Trie *child[MAX];
	Trie *fail;
	bool is_end;
	int word_length;
	Trie(){
		fill(child, child+MAX, nullptr);
		fail = nullptr;
		is_end = false;
		word_length = 0;
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
		node->word_length = word.size();
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

vector<int> pos_color;

void search_aho_color(Trie* root, string word){
	Trie* curr = root;
	for (int i=0;i<word.size();i++){
		int next = word[i] - 'a';
		while(curr != root && curr->child[next] == nullptr){
			curr = curr->fail;
		}
		if (curr->child[next] != nullptr){
			curr = curr->child[next];
		}
		if (curr->is_end) pos_color.push_back(i);
	}
}

vector<int> pos_team;

void search_aho_team(Trie* root, string word){
	Trie* curr = root;
	for (int i=0;i<word.size();i++){
		int next = word[i] - 'a';
		while(curr != root && curr->child[next] == nullptr){
			curr = curr->fail;
		}
		if (curr->child[next] != nullptr){
			curr = curr->child[next];
		}
		if (curr->is_end) pos_color.push_back(i);
	}	
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N, M;
	Trie* root_color = new Trie;
	Trie* root_team = new Trie;
	cin >> N >> M;
	for (int i=0;i<N;i++){
		string color;
		cin >> color;
		root_color->insert(color);
	}
	for (int i=0;i<M;i++){
		string team;
		cin >> team;
		root_team->insert(team);
	}
	
	construct_aho(root_color);
	construct_aho(root_team);
	
	int Q;
	cin >> Q;
	for (int i=0;i<Q;i++){
		string word;
		cin >> word;
		search_aho_color(root_color, word);
		for (int n: pos_color){
			cout << n << " ";
		}
		cout << endl;
		pos_color.clear();
	}
	
	
	return 0;
}

