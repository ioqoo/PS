#include <bits/stdc++.h>

const int MAX = 132000;
using namespace std;

int N;
char str[MAX];
//vector<int> cnt[MAX];
//vector<int> psum[MAX];

int solve(int l, int r, int c, vector<vector<int>>& psum){
	if (l==r) {
		if (str[l-1] - 'a' == c) return 0;
		else return 1;
	}
	int mid = (l+r) / 2;
	
	int left_char_cnt = psum[mid][c] - psum[l-1][c];
	int right_char_cnt = psum[r][c] - psum[mid][c];
	return min(solve(l, mid, c+1, psum) + ( (r-mid)-right_char_cnt ) , ( (mid-l+1) - left_char_cnt) + solve(mid+1, r, c+1, psum));
	
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &N);
		scanf("%s", str);
		
		vector<vector<int>> cnt(N+5, vector<int> (26));
		vector<vector<int>> psum(N+5, vector<int> (26));
		for (int i=0;i<N;i++){
			char curr = str[i];
			cnt[i+1][curr-'a'] = 1;
		}
		for (int i=0;i<26;i++){
			for (int j=1;j<=N;j++){
				psum[j][i] = psum[j-1][i] + cnt[j][i];
			}
		}
		
		printf("%d\n", solve(1, N, 0, psum));
		
	}
	
	
	return 0;
}


