#include <iostream>
#include <cstdio>
#include <string>

#define MAX 1005
#define ll long long

using namespace std;

int dp[MAX][MAX];
string str1, str2;
char ans[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> str1 >> str2;
	
	int str1_size = str1.size(), str2_size = str2.size();
	
	for (int i=1;i<=str1_size;i++){
		for (int j=1;j<=str2_size;j++){
			char c1 = str1[i-1], c2 = str2[j-1];
			if (c1 == c2) dp[i][j] = dp[i-1][j-1] + 1;
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	int LCSlen = dp[str1_size][str2_size];
	printf("%d\n", LCSlen);
	
	int t = LCSlen;
	
	
//	for (int i=0;i<=str1_size;i++){
//		for (int j=0;j<=str2_size;j++){
//			printf("%d ", dp[i][j]);
//		}
//		printf("\n");
//	}
	
	int ci = str1_size, cj = str2_size;
	
	while(t > 0){
		int curr = dp[ci][cj], up = dp[ci-1][cj], left = dp[ci][cj-1];
		if (curr == up+1 && curr == left+1){
			ans[t] = str1[ci-1];
			t--;
			ci--; cj--;
		}
		else if (curr == up){
			ci--;
		}
		else if (curr == left){
			cj--;
		}
	}
	
	for (int i=1;i<=LCSlen;i++){
		printf("%c", ans[i]);
	}
	printf("\n");
	

    return 0;
}
    
