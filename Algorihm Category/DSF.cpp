#include <bits/stdc++.h>

#define pii pair<int, int>
#define piii pair<int, pii>

using namespace std;

int V, E;
int dist[50][2];
pii pred[50][2];
priority_queue<piii, vector<piii>, greater<piii>> PQ;
vector<pii> graph[30];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d %d", &V, &E);
    for (int i=0;i<E;i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
    }
    
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    memset(pred, -1, sizeof(pred));
    dist[0][0] = 0;
    PQ.push({0, {0, 0}});
    while(!PQ.empty()){
        auto p = PQ.top(); PQ.pop();
        int curr_dist = p.first, curr = p.second.first, curr_cnt = p.second.second;
        if (curr_dist > dist[curr][curr_cnt]) continue;
        for (auto pp: graph[curr]){
            int next = pp.first, weight = pp.second;
            if (dist[next][curr_cnt] > dist[curr][curr_cnt] + weight){
                dist[next][curr_cnt] = dist[curr][curr_cnt] + weight;
                pred[next][curr_cnt] = {curr, curr_cnt};
                PQ.push({dist[next][curr_cnt], {next, curr_cnt}});
            }
            if (curr_cnt == 0 && dist[next][curr_cnt+1] > dist[curr][curr_cnt]){
                dist[next][curr_cnt+1] = dist[curr][curr_cnt];
                pred[next][curr_cnt+1] = {curr, curr_cnt};
                PQ.push({dist[next][curr_cnt+1], {next, curr_cnt+1}});
            }
        }
    }
    
//    for (int i=0;i<8;i++){
//        printf("vertex %d  -> change 0 times: %d / 1 times : %d\n", i, dist[i][0], dist[i][1]);
//    }
//
//    for (int i=0;i<8;i++){
//        printf("vertex %d -> change 0 times : %d / 1 times: %d\n", i, pred[i][0], pred[i][1]);
//    }

    int vertex = 7;
    int pre = pred[vertex][1].first, c = pred[vertex][1].second;
    while(vertex != 0){
        printf("%d %d %d\n", vertex, pre, c);
        vertex = pre;
        pre = pred[vertex][c].first, c = pred[vertex][c].second;
    }
    

    return 0;
}



