#include <bits/stdc++.h>

#define pii pair<int, int>
#define ll long long
const int INF = 0x3f3f3f3f;
const int MAX = 10005;
using namespace std;

int N, M; // entrance : 0, peak : N-1;
vector<pii> graph[MAX];
vector<pii> graph_rev[MAX];
int dist[MAX];
bool visited[MAX];
//int pcnt[MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d %d", &N, &M);
    int u, v, w;
    for (int i=0;i<M;i++){
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        graph_rev[u].push_back({v, w});
        graph_rev[v].push_back({u, w});
    }
    for (int i=0;i<N;i++){
        sort(graph[i].begin(), graph[i].end());
//        graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
    }
    
    memset(dist, INF, sizeof(dist));
    dist[0] = 0;
//    pcnt[0] = 1;
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    PQ.push({0, 0});
    
    
    
    while(!PQ.empty()){
        auto p = PQ.top(); PQ.pop();
        int curr = p.second, curr_dist = p.first;
        for (auto pp: graph[curr]){
            int next = pp.first, weight = pp.second;
            if (dist[next] > curr_dist + weight){
                dist[next] = curr_dist + weight;
//                pcnt[next] = pcnt[curr];
                PQ.push({dist[next], next});
            }
//            else if (dist[next] == curr_dist + weight){
//                pcnt[next] += pcnt[curr];
//            }
        }
    }
    int shortest = dist[N-1]; // ans = shortest * (path cnt)
    
    int pathweight = 0;
    queue<pii> Q;
    Q.push({N-1, dist[N-1]});
    visited[N-1] = true;
    while(!Q.empty()){
        auto p = Q.front(); Q.pop();
        int curr = p.first, curr_dist = p.second;
//        printf("%d %d\n", curr, curr_dist);
        for (auto pp: graph_rev[curr]){
            int next = pp.first, weight = pp.second;
            if (dist[next] == curr_dist-weight){
                pathweight += weight;
                if (visited[next]) continue;
                visited[next] = true;
                Q.push({next, dist[next]});
            }
        }
    }
    printf("%d\n", 2*pathweight);
    
    
    

    return 0;
}



