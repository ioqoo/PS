#include <bits/stdc++.h>
#define MAX 105

using namespace std;

int T;
int N, D;
int piles[MAX];


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
	
	scanf("%d", &T);
	for (int t=0;t<T;t++){
		scanf("%d %d", &N, &D);
		for (int i=0;i<N;i++){
			scanf("%d", &piles[i]);
		}
		int ans = piles[0];
		for (int i=1;i<N;i++){
			if (i*piles[i] > D){
				ans += D/i;
				break;
			}
			else{
				ans += piles[i];
				D -= i*piles[i];
			}
		}
		printf("%d\n", ans);
		
	}
	
}
