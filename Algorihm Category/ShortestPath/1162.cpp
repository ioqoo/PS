#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>

#define MAX 10005
#define ll long long
#define pll pair<ll, ll>
#define plll pair<ll, pll>
#define INF 10000000000LL

using namespace std;

int N, M, K;
vector<pll> graph[MAX];
ll dist[MAX][22]; // dist[i][j] = i번 노드까지 j번 포장해서 가는 최단거리 
priority_queue<plll, vector<plll>, greater<plll>> PQ;


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d %d %d", &N, &M, &K);
    ll u, v, w;
    for (int i=0;i<M;i++){
        scanf("%lld%lld%lld", &u, &v, &w);
        graph[u].push_back(pll(v, w));
        graph[v].push_back(pll(u, w));
    } 
    
    for (int i=1;i<=N;i++){
        for (int j=0;j<=K;j++){
            dist[i][j] = INF;
        }
    }
    
    dist[1][0] = 0;
    PQ.push(plll(0LL, pll(1LL, 0LL))); // curr_dist, curr, cnt
    while(!PQ.empty()){
        auto p = PQ.top();
        PQ.pop();
        ll curr_dist = p.first;
        ll curr = p.second.first;
        ll cnt = p.second.second;
        if (dist[curr][cnt] < curr_dist) continue;
        for (auto pp: graph[curr]){
            ll next = pp.first, weight = pp.second;
            if (dist[next][cnt] > dist[curr][cnt] + weight){
                dist[next][cnt] = dist[curr][cnt] + weight;
                PQ.push(plll(dist[next][cnt], pll(next, cnt)));
            }
            if (cnt < K && dist[next][cnt+1] > dist[curr][cnt]){
                dist[next][cnt+1] = dist[curr][cnt];
                PQ.push(plll(dist[next][cnt+1], pll(next, cnt+1)));
            }
        }
    }
    
    printf("%lld\n", *min_element(dist[N], dist[N]+K+1));
    
    

    return 0;
}

