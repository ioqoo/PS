#include <iostream>
#include <cstdio>
#define MAX 52
#define ll long long
#define lf long double
#define MOD 100000LL

using namespace std;

int M, N;
int stones[MAX];
lf ans;
int K;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
        
    scanf("%d", &M);
    for (int i=0;i<M;i++){
    	scanf("%d", &stones[i]);
    	N += stones[i];
	}
	scanf("%d", &K);
	
	for (int i=0;i<M;i++){
		int curr_stone = stones[i];
		if (curr_stone < K) continue;
		lf curr_prob = 1.;
		
		for (int t=0;t<K;t++){
			curr_prob *= (curr_stone-t);
			curr_prob /= (N-t);
		}
		ans += curr_prob;
	}
	
	printf("%.15LF", ans);
	
	
	
	

    return 0;
}
