#include <bits/stdc++.h>
using namespace std;
const int MAX = 11111;
typedef pair<int, int> pii;

int N;
int p[MAX];
int width[MAX];
// dp[x] : x 에서 곧게 시작하여 x~N 최소 휜 개수 
int dp[MAX];

int path(int idx){
    if(idx>=N) return 0; // 기저 
    
    int &ret = dp[idx];
    if(ret!=-1) return ret;
    
    ret = N-idx-1; // 남은거 다 휘는 경우 ( 최대 경우 )
    
    int pre = p[idx];
    int cnt = 0;
    for(int i=idx+1; i<N; ++i){
        int now = pre+width[i];
        
        // i 까지 잡아와서 딱 맞게 해주기 
        if(now <= p[i]) ret = min(ret, cnt+path(i));
        // 붙여서 가기        
        if(!(pre <= p[i] && now >= p[i])) cnt++;

        pre = now;
    }

    ret = min(ret, cnt);
    return ret;    
}

bool cmp(int a, int b){
    return p[a] < p[b];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N;
    
    for(int i=0; i<N; ++i) cin >> p[i];
    for(int i=0; i<N; ++i) cin >> width[i];
    
    vector<pii> V;
    for(int i=0; i<N; ++i) V.push_back(pii(p[i], width[i]));
    sort(V.begin(), V.end());
    for (int i=0;i<N;i++){
        p[i] = V[i].first;
        width[i] = V[i].second;
    }
    
    if(N<=2){
        cout << 0 << '\n';
    } 
    else{
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<N; ++i) path(i);
    
        int ans = N;
        for(int i=0; i<N; ++i) ans = min(ans, i+dp[i]);    
        
        cout << ans << '\n';
    }

    return 0;
}



