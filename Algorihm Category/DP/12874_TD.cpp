#include <bits/stdc++.h>

#define ll long long
const ll MOD = 1000000007;
const int MAX = 103;
using namespace std;

ll dp[MAX][MAX];
string S;

ll solve(int pos, int opencnt){
//    printf("pos : %d / opencnt : %d\n", pos, opencnt);
    if (opencnt < 0) return 0;
//    if (pos >= S.size() || opencnt < 0) return 0;
    ll &ret = dp[pos][opencnt];
    if (ret != -1LL) return ret%MOD;
//    if (pos >= S.size()) return 0;
    int nextopen = -1;
    for (int i=pos+1;i<S.size();i++){
        if (S[i] == '('){
            nextopen = i;
            break;
        }
    }
    int nextclose = -1;
    for (int i=pos+1;i<S.size();i++){
        if (S[i] == ')'){
            nextclose = i;
            break;
        }
    }
//    printf("nextopen : %d / nextclose : %d\n", nextopen, nextclose);
    ll A = (nextopen == -1 ? 0LL : solve(nextopen, opencnt+1))%MOD;
    ll B = (nextclose == -1 ? 0LL : solve(nextclose, opencnt-1))%MOD;
    ret = (A + B)%MOD;
    if (opencnt == 0) ret++;
    ret = ret%MOD;
//    printf("pos : %d / opencnt : %d finished\n\n", pos, opencnt);
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>S;
    int firstopen = -1;
    int lastclose = -1;
    for (int i=0;i<S.size();i++){
        if (S[i] == '('){
            firstopen = i;
            break;
        }
    }
    for (int i=S.size()-1;i>=0;i--){
        if (S[i] == ')'){
            lastclose = i;
            break;
        }
    }
    if (firstopen == -1 || lastclose == -1 || lastclose < firstopen){
        cout << "0\n";
        return 0;
    }
    
//    S = S.substr(firstopen, (lastclose-firstopen)+1);
    
    memset(dp, -1, sizeof(dp));
    cout << solve(firstopen, 1);
//    for (int i=0;i<5;i++){
//        for (int j=0;j<S.size();j++){
//            printf("%d ", dp[i][j]);
//        }
//        printf("\n");
//    }

    return 0;
}



