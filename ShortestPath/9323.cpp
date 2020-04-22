#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>

#define pii pair<int, int>
#define piii pair<int, pii>
#define pid pair<int, double>
#define pdi pair<double, int>
#define MAX 205
#define INF 987654321.0

using namespace std;

int T;
int N, M, S, E, s, p, y;
int u, v, prob, w;
vector<piii> graph[MAX];
double dist[MAX];
double dp[MAX][2]; // 0: paid, 1: free
bool visited[MAX];




int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &T);
    while(T>0){
       T--;
       
       scanf("%d %d %d %d %d %d %d", &N, &M, &S, &E, &s, &p, &y);
       
       for (int i=1;i<=N;i++){
           graph[i].clear();
       }
       
       fill(dist+1, dist+N+1, INF);
       memset(visited, 0, sizeof(visited));
       for (int i=1;i<=N;i++){
           dp[i][0] = dp[i][1] = INF;
       }
       
       for (int i=0;i<M;i++){
           scanf("%d %d %d %d", &u, &v, &prob, &w);
           graph[u].push_back(piii(v, pii(prob, w)));
           graph[v].push_back(piii(u, pii(prob, w)));
       }
       
       dp[S][0] = s*1.;
       dp[S][1] = 0.;
       dist[S] = 0.;
       priority_queue<pdi, vector<pdi>, greater<pdi>> PQ;
       PQ.push(pdi(dist[S], S));
       while(!PQ.empty()){
           auto ppp = PQ.top();
           PQ.pop();
           int curr = ppp.second;
           double curr_dist = ppp.first;
           if (visited[curr]) continue;
           visited[curr] = true;
           for (auto pp: graph[curr]){
               int next = pp.first;
               int next_prob = pp.second.first, next_weight = pp.second.second;
               dp[next][0] = min(dp[next][0], min(dp[curr][0] + next_weight*p*1., dp[curr][1] + next_weight*p*1. + s));
               dp[next][1] = min(dp[next][1], min(dp[curr][0], dp[curr][1]) + (y + next_weight*p)*(next_prob/100.0));
               double final_weight = min(dp[next][0], dp[next][1]);
               if (dist[next] > final_weight){
                   dist[next] = final_weight;
                   PQ.push(pdi(dist[next], next));
               }
           }
       }
       
       printf("%.2f\n", dist[E]);
       
       
   }

    return 0;
}

