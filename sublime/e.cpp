#include <bits/stdc++.h>

using namespace std;
const int MM = 500001;
const long long INF = 9999999999999999;
int W, N;
int arr[MM];
long long dp[MM];

long long ddd(int a){
	long long &ret = dp[a];
	if(a>=N) return 0;
	if(ret!=0) return ret;
	if(a == N-1) return ret = (W-arr[N-1])*(W-arr[N-1]);
	int now = a;
	long long wwnow = arr[a];
	long long temp;
	ret = max((W-wwnow)*(W-wwnow),ddd(now+1));
	long long mini = INF;
	while(now+1<N && W>=(wwnow+arr[now+1])){
		now+=1;
		wwnow+=arr[now];
		mini = min(mini,max((W-wwnow)*(W-wwnow),dp[now+1]));
	}
	ret = min(ret, mini);
	return ret; 
}


int main(){

scanf("%d %d", &W, &N);

for (int i = 0; i < N; ++i)
	scanf("%d", &arr[i]);

cout << ddd(0) << '\n';
    
}