#include <bits/stdc++.h>
#define MAX 1000000000LL
#define ll long long

using namespace std;

ll N, M, K;
ll dp[101][101];
string answer;

void solve(ll n, ll m, ll remain){
    if (n == 0){
        for (int i=0;i<m;i++){
            answer += 'z';
        }
        return;
    }
    else if (m == 0){
        for (int i=0;i<n;i++){
            answer += 'a';
        }
        return;
    }

    if (dp[n-1][m] >= remain){
        answer += 'a';
        solve(n-1, m, remain);
    }
    else{
        answer += 'z';
        solve(n, m-1, remain - dp[n-1][m]);
    }

    return;
    // remain : 앞으로 남은 순번
    // dp[n-1][m] : 이번에 a를 넣었을 때,
    // 그 뒤에 나머지 a와 z로 만들 수 있는 단어의 경우의 수
    // dp[n-1][m] >= remain : 이번에 a를 넣어도
    // 뒤에 만들 수 있는 경우의 수가 충분히 남아 있음
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    for (ll i=0LL;i<=N;i++){
        for (ll j=0LL;j<=M;j++){
            if (i==0 || j==0) dp[i][j] = 1LL;
            else{
                dp[i][j] = dp[i][j-1] * (i+j) / j > MAX ? MAX + 1LL : dp[i][j-1] * (i+j) / j;
            }
        }
    }

    if (K > dp[N][M]){
        cout << "-1\n";
        return 0;
    }

    solve(N, M, K);
    cout << answer << "\n";


}
