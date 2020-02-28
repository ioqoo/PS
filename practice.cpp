#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 1000005

using namespace std;

int N;
vector<int> graph[MAX];
vector<int> tree[MAX];
int dp[MAX][2];
bool visited[MAX];

void make_tree(int curr){
    visited[curr] = true;
    
    for (int next: graph[curr]){
        if (visited[next]) continue;
        tree[curr].push_back(next);
        make_tree(next);
    }
    return;
}

int solve(int curr, int stat){
    int& ret = dp[curr][stat];
    if (ret != -1) return ret;
    
    ret = 0;
    
    if (stat){
        for (int next: tree[curr]){
            ret += min(solve(next, 0), solve(next, 1));
        }
        ret++;
    }
    else{
        for (int next: tree[curr]){
            ret += solve(next, 1);
        }
    }
    
    return ret;
}




int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    int u, v;
    for (int i=0;i<N-1;i++){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    make_tree(1);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", min(solve(1, 0), solve(1, 1)));
    
   
    return 0;
}
