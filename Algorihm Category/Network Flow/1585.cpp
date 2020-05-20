#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

const int INF = 987654321;
const int MAX = 130;
const int S = 110;
const int E = 111;

using namespace std;

int N, T, F;
int enter[MAX], leave[MAX];
vector<int> graph[MAX];
int c[MAX][MAX], f[MAX][MAX], w[MAX][MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        scanf("%d", &enter[i]);
    }
    
    for (int i=0;i<N;i++){
        scanf("%d", &leave[i]);
    }
    
    scanf("%d %d", &T, &F);
    
    for (int i=0;i<N;i++){
        graph[S].push_back(i);
        graph[i].push_back(S);
        c[S][i] = 1;
        graph[i+50].push_back(E);
        graph[E].push_back(i+50);
        c[i+50][E] = 1;
    }
    
    for (int i=0;i<N;i++){
        int en = enter[i];
        for (int j=0;j<N;j++){
            int le = leave[j];
            if (le <= en) continue;
            int S = le - en;
            int weight;
            if (S >= T) weight = 0;
            else weight = min(F, (T-S) * (T-S));
            graph[i].push_back(j+50);
            graph[j+50].push_back(i);
            c[i][j+50] = INF;
            w[i][j+50] = weight;
            w[j+50][i] = -weight;
        }
    }
    
    int totalw = 0;
    for (int i=0;i<N;i++){
        int pre[MAX], dist[MAX];
        bool inQ[MAX] = {0,};
        fill(pre, pre+MAX, -1);
        fill(dist, dist+MAX, INF);
        queue<int> Q;
        Q.push(S);
        dist[S] = 0;
        inQ[S] = true;
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
        if (pre[E] == -1){
            printf("-1\n");
            return 0;
        }
        
        for (int i=E;i!=S;i=pre[i]){
            totalw += w[pre[i]][i];
            f[pre[i]][i]++;
            f[i][pre[i]]--;
        }
    }
    printf("%d ", totalw);
    totalw = 0;
    
    memset(f, 0, sizeof(f));
    for (int i=0;i<MAX;i++){
        for (int j=0;j<MAX;j++){
            w[i][j] *= -1;
        }
    }
    
    for (int i=0;i<N;i++){
        int pre[MAX], dist[MAX];
        bool inQ[MAX] = {0,};
        fill(pre, pre+MAX, -1);
        fill(dist, dist+MAX, INF);
        queue<int> Q;
        Q.push(S);
        dist[S] = 0;
        inQ[S] = true;
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
        
        for (int i=E;i!=S;i=pre[i]){
            totalw += w[pre[i]][i];
            f[pre[i]][i]++;
            f[i][pre[i]]--;
        }
    }
    printf("%d\n", -totalw);    
    
    

    return 0;
}



