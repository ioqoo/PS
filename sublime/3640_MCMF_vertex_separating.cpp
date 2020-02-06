#include <bits/stdc++.h>
const int INF = 987654321;
const int MAX_N = 1000;
const int MAX_V = 2*MAX_N;
using namespace std;

int V, E;
int C[MAX_V][MAX_V];
int F[MAX_V][MAX_V];
int D[MAX_V][MAX_V];
vector<int> graph[MAX_V];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    while(scanf("%d", &V)!=EOF){
        scanf("%d", &E);
        for (int i=0;i<MAX_V;i++){
            graph[i].clear();
        }
        memset(C, 0, sizeof(C));
        memset(F, 0, sizeof(F));
        memset(D, 0, sizeof(D));
        for (int x=0;x<E;x++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            u--; v--;
            // 0 : in, 1 : out
            // n*2 : in, n*2 + 1 : out
            graph[u*2+1].push_back(v*2);
            graph[v*2].push_back(u*2+1);
            C[u*2+1][v*2] = 1;
            D[u*2+1][v*2] = w;
            D[v*2][u*2+1] = -w;
        }
        for (int i=0;i<V;i++){
            graph[i*2].push_back(i*2+1);
            graph[i*2+1].push_back(i*2);
            C[i*2][i*2+1] = 1;
        }

        int cost = 0;
        int nnn = 2;
        while(nnn--){
            int prev[MAX_V], dist[MAX_V];
            bool in_Q[MAX_V] = {0,};
            queue<int> Q;
            fill(prev, prev+MAX_V, -1);
            fill(dist, dist+MAX_V, INF);
            dist[1] = 0;
            in_Q[1] = true;
            Q.push(1);

            while(!Q.empty()){
                int curr = Q.front();
                Q.pop();
                in_Q[curr] = false;
                for (int next: graph[curr]){
                    if (C[curr][next] - F[curr][next] > 0 && dist[next] > dist[curr] + D[curr][next]){
                        dist[next] = dist[curr] + D[curr][next];
                        prev[next] = curr;
                        if(!in_Q[next]){
                            Q.push(next);
                            in_Q[next] = true;
                        }
                    }
                }
            }
            if (prev[2*(V-1)] == -1) break;

            for (int i=2*(V-1);i!=1;i=prev[i]){
                cost += D[prev[i]][i];
                F[prev[i]][i] += 1;
                F[i][prev[i]] -= 1;
            }
        }
        printf("%d\n", cost);
    }
}
