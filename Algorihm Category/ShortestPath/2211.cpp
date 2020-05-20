#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define pii pair<int, int>
#define MAX 1005
#define INF 987654321

using namespace std;

int N, M;
vector<pii> graph[MAX];
priority_queue<pii, vector<pii>, greater<pii>> PQ;
int dist[MAX];
bool visited[MAX];
int previ[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d %d", &N, &M);
    int u, v, w;
    for (int i=0;i<M;i++){
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(pii(v, w));
        graph[v].push_back(pii(u, w));
    }
    
    fill(dist+1, dist+N+1, INF);
    dist[1] = 0;
    PQ.push(pii(0, 1));
    while(!PQ.empty()){
        auto p = PQ.top();
        PQ.pop();
        int curr = p.second, curr_dist = p.first;
        if (visited[curr]) continue;
        visited[curr] = true;
        for (auto pp: graph[curr]){
            int next = pp.first, weight = pp.second;
            if (dist[next] > curr_dist + weight){
                previ[next] = curr;
                dist[next] = curr_dist + weight;
                PQ.push(pii(dist[next], next));
            }
        }
    }
    
    vector<pii> ans;
    int ans_cnt = 0;
    for (int i=1;i<=N;i++){
        if (previ[i] != 0){
            ans_cnt++;
            ans.push_back(pii(i, previ[i]));
        }
    }
    printf("%d\n", ans_cnt);
    for (auto p: ans){
        printf("%d %d\n", p.first, p.second);
    }

    

    return 0;
}

