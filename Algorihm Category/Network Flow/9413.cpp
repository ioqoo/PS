#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

const int INF = 987654321;
const int MAX = 630;
const int S = 610;
const int E = 611;

using namespace std;

int T, N, M;
vector<int> graph[MAX];
int c[MAX][MAX], f[MAX][MAX], w[MAX][MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &T);
    while(T--){
        
        scanf("%d %d", &N, &M);
        for (int i=0;i<MAX;i++){
            graph[i].clear();
        }
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));
        memset(w, 0, sizeof(w));
        
        int u, v;
        for (int i=0;i<M;i++){ // 0, 2, 4 : in, 1, 3, 5 : out
            scanf("%d %d", &u, &v);
            u--; v--;
            int uout = u*2+1, vin = v*2;
            graph[uout].push_back(vin);
            graph[vin].push_back(uout);
            c[uout][vin] = 1;
        }
        for (int i=0;i<N;i++){
            int in = i*2, out = i*2+1;
            graph[in].push_back(out);
            graph[out].push_back(in);
            w[in][out] = -1;
            w[out][in] = 1;
            c[in][out] = 1;
            
            graph[S].push_back(in);
            graph[in].push_back(S);
            c[S][in] = 1;
            graph[out].push_back(E);
            graph[E].push_back(out);
            c[out][E] = 1;
        }
        
        int totalw = 0;
        int t = 2;
        while(t--){
            int pre[MAX], dist[MAX];
            bool inQ[MAX] = {0,};
            fill(pre, pre+MAX, -1);
            fill(dist, dist+MAX, INF);
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
            
            for (int i=E;i!=S;i=pre[i]){
                totalw += w[pre[i]][i];
                f[pre[i]][i]++;
                f[i][pre[i]]--;
            }
        }
        printf("%d\n", -totalw);
    }
    

    return 0;
}



