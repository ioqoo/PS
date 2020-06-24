#include <bits/stdc++.h>

#define ll long long
const int MAX = 5005;

using namespace std;

struct P{
    ll x, y;
    
    bool operator < (const P &B){
        if (x == B.x) return y < B.y;
        return x < B.x;
    }
    
    ll area(){
        return x*y;
    }
};

int N;
vector<P> points;
ll dp[MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d", &N);
    ll x, y;
    for (int i=0;i<N;i++){
        scanf("%lld %lld", &x, &y);
        points.push_back({abs(x), abs(y)});
    }
    sort(points.begin(), points.end());
    
    vector<P> use;
    int pos = N-1;
    P last = points[pos];
    while(pos >= 0){
        auto curr = points[pos];
        if (curr.y > last.y){
            use.push_back(last);
            last = curr;
        }
        pos--;
    }
    use.push_back(last);
    sort(use.begin(), use.end());
    
//    fill(dp, dp+MAX, INF);
    N = use.size();
    dp[0] = 0;
    dp[1] = use[0].area();
    
    for (int i=2;i<=N;i++){
        dp[i] = use[0].y * use[i-1].x;
        for (int j=0;j<i;j++){
//            printf("%lld\n", dp[j] + use[j].y * use[i-1].x);
            dp[i] = min(dp[i], dp[j] + use[j].y * use[i-1].x);
        }
    }
    
    printf("%lld\n", dp[N]*4LL);

    return 0;
}



