#include <iostream>
#include <cstring>

#define MAX 2005
#define ll long long

using namespace std;

int N;
ll cakes[MAX];
ll dp[MAX][MAX];
// dp[i][j] : 현재까지 i ~ j번 조각이 없어졌을 때, 남은 조각들에서 JOI가 가져올 수 있는 총 값의 최댓값 
// 구간 이용하는 사선 dp랑 비슷하지만 보는 구간이 (i ~ j)의 여집합인 것이 다름 

int goright(int pos) {
	return (pos+1)%N;
}

int goleft(int pos){
	return (pos+N-1)%N;
}

ll IOI(int start, int end);
ll JOI(int start, int end);

ll IOI(int start, int end){
	if (goright(end) == start) return 0;
	
	if (cakes[goleft(start)] < cakes[goright(end)]) return JOI(start, goright(end));
	else return JOI(goleft(start), end);
}

ll JOI(int start, int end){
	ll &ret = dp[start][end];
	if (ret != -1) return ret;
	
	if (goright(end) == start) return ret = 0;
	
	ll L = cakes[goleft(start)] + IOI(goleft(start), end);
	ll R = cakes[goright(end)] + IOI(start, goright(end));
	
	return ret = max(L, R);
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
    scanf("%d", &N);
    for (int i=0;i<N;i++){
    	scanf("%lld", &cakes[i]);
	}
	
	ll ans = 0;
	memset(dp, -1, sizeof(dp));
	for (int i=0;i<N;i++){
		ans = max(ans, cakes[i] + IOI(i, i));
	}
	printf("%lld\n", ans);
	
//	for (int i=0;i<N;i++){
//		for (int j=0;j<N;j++){
//			printf("%3lld ", dp[i][j]);
//		}
//		printf("\n");
//	}
	

    return 0;
}
