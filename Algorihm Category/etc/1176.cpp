#include <bits/stdc++.h>
#define ll long long
const int MAX = (1<<16);

using namespace std;

int N, K;
vector<int> arr;
ll dp[MAX + 11][18];

ll solve(int state, int last){
    if ( state == (1 << N) - 1 ) return 1LL;
    ll &ret = dp[state][last];

    if (ret != -1) return ret;
    ret = 0;
    
    for (int i=0;i<N;i++){
        if ( ((1<<i) & state) != 0 ) continue;
        
        if (last == N){
            ret += solve(state|(1<<i), i);
        }
        else{
            if (abs(arr[i] - arr[last]) > K){
                ret += solve(state|(1<<i), i);
            }
        }
    }
    
    return ret;
    
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d %d", &N, &K);
    for (int i=0;i<N;i++){
        int temp;
        scanf("%d", &temp);
        arr.push_back(temp);
    }
    
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", solve(0, N));
    

    return 0;
}



