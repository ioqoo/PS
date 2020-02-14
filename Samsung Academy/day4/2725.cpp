#include <bits/stdc++.h>
#define MAX 1001
#define ll long long

using namespace std;

int C;
bool novision[MAX][MAX];
int ans[MAX];

int GCD(int a, int b){
	if (b == 0) return a;
	
	return GCD(b, a%b);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &C);
    
    
    novision[0][0] = true;
    for (int i=2;i<MAX;i++){
    	novision[0][i] = true;
    	novision[i][0] = true;
	}
    
    for (int i=1;i<MAX;i++){
    	for (int j=1;j<MAX;j++){
    		int gcd = GCD(i, j);
    		if (gcd == 1){
    			int x = i*2, y = j*2;
    			while(x < MAX && y < MAX){
    				novision[x][y] = true;
    				x += i; y += j;
				}
			}
		}
	}
	
	for (int i=0;i<MAX;i++){
		for (int j=0;j<MAX;j++){
			if (!novision[i][j]){
				ans[max(i, j)]++;
			}
		}
	}
	for (int i=1;i<MAX;i++){
		ans[i] += ans[i-1];
	}
	
	
    
    for (int t=0;t<C;t++){
    	int n;
    	scanf("%d", &n);
    	printf("%d\n", ans[n]);
	}


    return 0;
}
