#include <bits/stdc++.h>

const int MAX = 1005;
using namespace std;

int N, X;
vector<int> graph[MAX];
bool visited[MAX];
int st[MAX], en[MAX];
int order = 0;

void dfs(int curr){
    st[curr] = order++;
    visited[curr] = true;
    for (int next: graph[curr]){
        if (visited[next]) continue;
        dfs(next);
    }
    en[curr] = order;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    scanf("%d", &t);
    while(t--){
        for (int i=0;i<N;i++){
            graph[i].clear();
        }
        memset(visited, 0, sizeof(visited));
        memset(st, 0, sizeof(st));
        memset(en, 0, sizeof(en));
        order = 0;
        scanf("%d %d", &N, &X);
        for (int i=0;i<N-1;i++){
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(1);
        
        int Xa = en[X] - st[X] - 1;
        if (Xa == 0){
            printf("Ayush\n");
            continue;
        }
        int Xb = N - Xa - 1;
        if (Xb == 0){
            if ((Xa-1) % 2 == 0){
                printf("Ayush\n");
            }
            else printf("Ashish\n");
            continue;
        }
        if ( (max(Xa-1, 0) + max(Xb-1, 0)) % 2 == 0 ) {
            printf("Ashish\n");
        }
        else printf("Ayush\n");
        
    }

    return 0;
}



