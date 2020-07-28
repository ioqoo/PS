#include <bits/stdc++.h>
const int MAX = 2;
using namespace std;

int H_p, W_p, H_m, W_m;
map<string, int> mp;
vector<int> P;
string M[2005];
int pos[2005][2005];


struct Trie{
	Trie *child[MAX];
	Trie *fail;
	int end_num;
	Trie(){
		fill(child, child+MAX, nullptr);
		fail = nullptr;
		end_num = -1;
	}
	~Trie(){
		for (int i=0;i<MAX;i++){
			if (child[i]) delete child[i];
		}
	}
	void insert(Trie* root, string word){
		Trie* node = root;
		for (int i=0;i<word.length();i++){
			int c = word[i] - '0';
			if (node->child[c] == nullptr) {
				node->child[c] = new Trie();
			}
			node = node->child[c];
		}
		node->end_num = mp[word];
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
			
			if (next->fail->end_num != -1) {
				next->end_num = next->fail->end_num;
			}
			
			Q.push(next);
		}	
	}
}

vector<int> make_pi(int col_num){
	vector<int> ret(H_m);
	
	for (int i=1, j=0;i<H_m;i++){
		while(j > 0 && pos[i][col_num] != pos[j][col_num]) j = ret[j-1];
		if (pos[i][col_num] == pos[j][col_num]) ret[i] = ++j;
	}
	
	return ret;
	
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(pos, -1, sizeof(pos));
	
	cin >> H_p >> W_p >> H_m >> W_m;
	Trie* root = new Trie;
	int piv = 0;
	for (int i=0;i<H_p;i++){
		string row;
		cin >> row;
		for (int j=0;j<W_p;j++){
			row[j] = row[j]=='x'?'0':'1';
		}
		if (!mp.count(row)) {
			mp[row] = piv++;
			root->insert(root, row);
		}
		P.push_back(mp[row]);
		
	}
	construct_aho(root);
	
	for (int i=0;i<H_m;i++){
		string row;
		cin >> row;
		for (int j=0;j<W_m;j++){
			row[j] = row[j]=='x'?'0':'1';
		}
		M[i] = row;		
	}
	
	for (int i=0;i<H_m;i++){
		Trie* curr = root;
		for (int j=0;j<W_m;j++){
			int next = M[i][j] - '0';
			while(curr != root && curr->child[next] == nullptr){
				curr = curr->fail;
			}
			if (curr->child[next] != nullptr){
				curr = curr->child[next];
			}
			if (curr->end_num != -1) pos[i][j] = curr->end_num;
		}
	}
	int ans = 0;
	for (int c=0;c<W_m;c++){
		vector<int> fail = make_pi(c);
		for (int i=0, j=0;i<H_m;i++){
			while(j>0 && pos[i][c] != P[j]) j = fail[j-1];
			if (pos[i][c] == P[j]){
				if (j == H_p-1) {
					ans++;
					j = fail[j];
				}
				else j++;
			}
		}
	}
	cout << ans << endl;
	
	
	return 0;
}


