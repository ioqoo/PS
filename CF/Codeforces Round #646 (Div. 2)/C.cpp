#include <bits/stdc++.h>

const int MAX = 1005;
using namespace std;

int N, X;
vector<int> graph[MAX];
bool visited[MAX];
bool visited2[MAX];
int childcnt[MAX];
bool ispre[MAX];

int dfs(int curr){
    visited[curr] = true;
    int temp = 0;
    bool succ = false;
    for (int next: graph[curr]){
        if (visited[next]) continue;
        succ = true;
        temp += dfs(next);
    }
    if (!succ){
        childcnt[curr] = 1;
        return 1;
    }
    childcnt[curr] = temp;
    return temp;
}

bool chk(int curr){
    visited2[curr] = true;
    bool ret = false;
    if (curr == X) return true;
    for (int next: graph[curr]){
        if (visited2[next]) continue;
        if (dfs(next) == true){
            ispre[curr] = true;
            ret = true;
        }
    }
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    scanf("%d", &t);
    while(t--){
        for (int i=0;i<MAX;i++){
            graph[i].clear();
        }
        memset(visited, 0, sizeof(visited));
        memset(visited2, 0, sizeof(visited2));
        memset(childcnt, 0, sizeof(childcnt));
        memset(ispre, 0, sizeof(ispre));
        
        scanf("%d %d", &N, &X);
        for (int i=0;i<N-1;i++){
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        dfs(1);
        chk(1);
        
        for (int i=1;i<=N;i++){
            printf("%d ", ispre[i]);
        }
    }

    return 0;
}



