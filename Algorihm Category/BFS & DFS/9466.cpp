#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int T;
int E[MAX];
int cnt;
bool visited[MAX];
bool finished[MAX];

void DFS(int u){
    visited[u] = true;
    int v = E[u];
    if (visited[v]){
        if (!finished[v]){
            cnt++;
            for (int start = v; start != u; start = E[start]){
                cnt++;
            }
        }
    }
    else{
        DFS(v);
    }
    finished[u] = true;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &T);
    for (int x=0;x<T;x++){
        int n;
        scanf("%d", &n);

        cnt = 0;
        fill(visited+1, visited+n+1, 0);
        fill(finished+1, finished+n+1, 0);

        for (int u=1;u<=n;u++){
            int v;
            scanf("%d", &v);
            E[u] = v;
        }
        for (int u=1;u<=n;u++){
            if (!visited[u]){
                DFS(u);
            }
        }
        printf("%d\n", n - cnt);
    }
}
