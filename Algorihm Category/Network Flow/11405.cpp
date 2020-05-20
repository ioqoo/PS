#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

const int INF = 987654321;
const int MAX = 222;
const int S = 210;
const int E = 211;

using namespace std;

int N, M;
int c[MAX][MAX], f[MAX][MAX], w[MAX][MAX];
vector<int> graph[MAX];


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d %d", &N, &M);
    int temp;
    for (int i=1;i<=N;i++){
        scanf("%d", &temp);
        graph[i+100].push_back(E);
        graph[E].push_back(i+100);
        c[i+100][E] = temp;
    }
    for (int i=1;i<=M;i++){
        scanf("%d", &temp);
        graph[S].push_back(i);
        graph[i].push_back(S);
        c[S][i] = temp;
    }
    for (int i=1;i<=M;i++){
        for (int j=1;j<=N;j++){
            scanf("%d", &temp);
            graph[i].push_back(j+100);
            graph[j+100].push_back(i);
            c[i][j+100] = INF;
            w[i][j+100] = temp;
            w[j+100][i] = -temp;
        }
    }
    
    int totalw = 0;
    while(1){
        int pre[MAX], dist[MAX];
        bool inQ[MAX] = {0,};
        fill(pre, pre+MAX, -1);
        fill(dist, dist+MAX, INF);
        queue<int> Q;
        dist[S] = 0;
        inQ[S] = true;
        Q.push(S);
        
        while(!Q.empty()){
            int curr = Q.front(); Q.pop(); inQ[curr] = false;
            for (int next: graph[curr]){
                if (c[curr][next] - f[curr][next] > 0 && dist[curr] + w[curr][next] < dist[next]){
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
            totalw += flow * w[pre[i]][i];
            f[pre[i]][i] += flow;
            f[i][pre[i]] -= flow;
        }
    }
    printf("%d\n", totalw);
    

    return 0;
}



