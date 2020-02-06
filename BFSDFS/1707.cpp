#include <bits/stdc++.h>
#define MAX 20005

using namespace std;

vector<int> graph[MAX];
int color[MAX];

void DFS(int curr){
    int next_color = color[curr]==1 ? 2 : 1;

    for (int next: graph[curr]){
        if (color[next] != 0) continue;
        color[next] = next_color;
        DFS(next);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int K;
    scanf("%d", &K);
    for (int i=0;i<K;i++){
        int V, E;
        scanf("%d %d", &V, &E);
        fill(color+1, color+V+1, 0);
        for (int i=1;i<=V;i++){
            graph[i].clear();
        }
        for (int i=0;i<E;i++){
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i=1;i<=V;i++){
            if (color[i] == 0) DFS(i);
        }

        int succ = true;
        for (int u=1;u<=V;u++){
            for (int v: graph[u]){
                if (color[u] == color[v]){
                    succ = false;
                    break;
                }
            }
            if (!succ) break;
        }

        if (succ) printf("YES\n");
        else printf("NO\n");

    }

    return 0;

}
