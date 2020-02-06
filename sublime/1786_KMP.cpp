#include <bits/stdc++.h>
#define ll long long
#define MIN -100000
#define MAX 100000
using namespace std;

vector<int> getPi(string p){
	int m = p.size(), j = 0;
	vector<int> pi(m, 0);
	for (int i=1;i<m;i++){
		while (j>0 && p[i]!=p[j]){
			j = pi[j-1];
		}
		if (p[i] == p[j]){
			pi[i] = ++j;
		}
	}
	return pi;
}

vector<int> kmp(string H, string N){
	vector<int> ans;
	auto pi = getPi(N);
	int n = H.size(), m = N.size(), j = 0;
	for (int i=0;i<n;i++){
		while(j>0 && H[i] != N[j]){
			j = pi[j-1];
		}
		if (H[i] == N[j]){
			if (j==m-1){
				ans.push_back(i-m+1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}

int main(){
	string H, N;
	getline(cin, H);
	getline(cin, N);
	auto answer = kmp(H,N);
	int ans_size = answer.size();
	cout << ans_size << "\n";
	for (auto &p: answer){
		cout << p + 1 << "\n";
	}
}