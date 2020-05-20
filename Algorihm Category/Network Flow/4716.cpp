#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <queue>

const int INF = 987654321;
const int MAX = 1100;
const int S = 1050;
const int E = 1051;
const int A = 1052;
const int B = 1053;

using namespace std;

int N, a, b;
vector<int> graph[MAX];
int c[MAX][MAX], f[MAX][MAX], w[MAX][MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    while(1){
        scanf("%d %d %d", &N, &a, &b);
        if (N == 0) break;
        
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));
        memset(w, 0, sizeof(w));
        for (int i=0;i<MAX;i++){
            graph[i].clear();
        }
        int k, da, db;
        for (int i=0;i<N;i++){
            scanf("%d %d %d", &k, &da, &db);
            graph[i].push_back(E);
            graph[E].push_back(i);
            c[i][E] = k;
            
            graph[A].push_back(i);
            graph[i].push_back(A);
            c[A][i] = INF;
            w[A][i] = da;
            w[i][A] = -da;
            
            graph[B].push_back(i);
            graph[i].push_back(B);
            c[B][i] = INF;
            w[B][i] = db;
            w[i][B] = -db;
        }
        graph[S].push_back(A);
        graph[A].push_back(S);
        c[S][A] = a;
        graph[S].push_back(B);
        graph[B].push_back(S);
        c[S][B] = b;
        
        int totalw = 0;
        while(1){
            int pre[MAX], dist[MAX];
            fill(pre, pre+MAX, -1);
            fill(dist, dist+MAX, INF);
            bool inQ[MAX] = {0,};
            queue<int> Q;
            Q.push(S);
            inQ[S] = true;
            dist[S] = 0;
            while(!Q.empty()){
                int curr = Q.front(); Q.pop(); inQ[curr] = false;
                for (int next: graph[curr]){
                    if (c[curr][next] - f[curr][next] > 0 && dist[next] > dist[curr] + w[curr][next]){
                        dist[next] = dist[curr] + w[curr][next];
                        pre[next] = curr;
                        if (!inQ[next]){
                            Q.push(next);
                            inQ[next] = true;
                        }
                    }
                }
            }
            if (pre[E] == -1) break;
            
            int flow = INF;
            for (int i=E;i!=S;i=pre[i]){
                flow = min(flow, c[pre[i]][i] - f[pre[i]][i]);
            }
            for (int i=E;i!=S;i=pre[i]){
                totalw += w[pre[i]][i] * flow;
                f[pre[i]][i] += flow;
                f[i][pre[i]] -= flow;
            }
        }
        printf("%d\n", totalw);
        
    }

    return 0;
}



