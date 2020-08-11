#include <bits/stdc++.h>
const int MAX = 26;
#define ll long long
const ll MOD = 1e9+7;
using namespace std;

struct Trie{
	Trie* child[MAX];
	int cnt;
	Trie(){
		fill(child, child+MAX, nullptr);
		cnt = 0;
	}
	~Trie(){
		for (int i=0;i<MAX;i++){
			if (child[i]) delete child[i];
		}
	}
	
	void insert(string word){
		Trie* node = this;
		for (int i=0;i<word.size();i++){
			char c = word[i];
			if (!node->child[c-'a']) node->child[c-'a'] = new Trie;
			node = node->child[c-'a'];
			node->cnt++;
		}
	}
};

ll dp[200005];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;
	cin >> N;
	Trie* root = new Trie;
	for (int i=0;i<N;i++){
		string word;
		cin >> word;
		root->insert(word);
	}
	string str;
	cin >> str;
	int M = str.size();
	dp[0] = 1;
	for (int i=0;i<M;i++){
		Trie* node = root;
		for (int j=0;i+j<M;j++){
			char next = str[i+j];
			if (!node->child[next-'a']) break;
			dp[i+j+1] = (dp[i+j+1] + (ll)(node->child[next-'a']->cnt) * dp[i])%MOD;
			node = node->child[next-'a'];
		}
	}
	cout << dp[M];
	
	
	return 0;
}


