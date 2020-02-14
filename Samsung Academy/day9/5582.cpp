#include <iostream>
#include <cstdio>
#include <string> 

#define MAX 4005
#define ll long long

using namespace std;

int dp[MAX][MAX];
int ans;
string str1, str2;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> str1 >> str2;
	int str1_size = str1.size();
	int str2_size = str2.size();
	
	for (int i=1;i<=str1_size;i++){
		for (int j=1;j<=str2_size;j++){
			char c1 = str1[i-1], c2 = str2[j-1];
			if (c1 == c2) {
				dp[i][j] = dp[i-1][j-1]+1;
				ans = max(ans, dp[i][j]);
			}
		}
	}
	printf("%d\n", ans);

    return 0;
}
    
