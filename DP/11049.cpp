#include <bits/stdc++.h>
#define MAX 505
#define ll long long
#define pll pair<ll, ll>
#define INF 1e11

using namespace std;

int N;
pll mat[MAX]; // first : row, second : column
ll dp[MAX][MAX];


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        ll r, c;
        scanf("%lld %lld", &r, &c);
        mat[i] = pll(r, c);
    }
    for (int i=1;i<N;i++){
        dp[i][i+1] = mat[i].first * mat[i].second * mat[i+1].second;
    }
    for (int d=2;d<=N-1;d++){
        for (int i=1;i<=N-d;i++){
            ll curr_min = INF;
            int j = i + d;
            for (int k=i;k<j;k++){
                curr_min = min(curr_min, mat[i].first * mat[k].second * mat[j].second + dp[i][k] + dp[k+1][j]);
            }
            dp[i][i+d] = curr_min;
        }
    }

    printf("%lld\n", dp[1][N]);
}
