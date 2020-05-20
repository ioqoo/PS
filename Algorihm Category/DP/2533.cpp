#include <bits/stdc++.h>
#define MAX 1000005

using namespace std;

int N;
vector<int> adj[MAX];
vector<int> child[MAX];
bool visited[MAX];
int dp[MAX][2];

void make_tree(int curr){
    visited[curr] = true;

    for (int next: adj[curr]){
        if (!visited[next]){
            child[curr].push_back(next);
            make_tree(next);
        }
    }
}

int root(int curr, int stat){
    int& ret = dp[curr][stat];
    if (ret != -1) return ret;
    // DP : MEMOIZATION
    // Line 26을 안 써주면 여러 번 나올 수 있는 dp[2][1] 등과 같은 값을 계속 계산해 주어야 함

    ret = 0;

    if (!stat) {
        for (int next: child[curr]){
            ret += root(next, 1);
        }
    }
    else{
        for (int next: child[curr]){
            ret += min(root(next, 0), root(next, 1));
        }
        ret++; // stat == 1 -> curr가 얼리어답터임
    }

    return ret;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);
    for (int i=0;i<N;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    make_tree(1);

    memset(dp, -1, sizeof(dp));
    printf("%d\n", min(root(1, 0), root(1, 1)));

}
