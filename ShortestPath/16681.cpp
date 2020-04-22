#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define MAX 100005
#define ll long long
#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define INF 1000000000000LL

using namespace std;

int N, M;
ll D, E;
ll height[MAX];
int u, v;
ll w;
vector<pil> graph[MAX];
ll dist_asc[MAX];
ll dist_des[MAX];
priority_queue<pli, vector<pli>, greater<pli>> PQ_asc;
priority_queue<pli, vector<pli>, greater<pli>> PQ_des;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

    scanf("%d %d %lld %lld", &N, &M, &D, &E);
    for (int i=1;i<=N;i++){
        scanf("%lld", &height[i]);
    }
    
    for (int i=0;i<M;i++){
        scanf("%d %d %lld", &u, &v, &w);
        graph[u].push_back(pil(v, w));
        graph[v].push_back(pil(u, w));
    }
    
    fill(dist_asc+1, dist_asc+N+1, INF);
    fill(dist_des+1, dist_des+N+1, INF);
    dist_asc[1] = 0LL;
    PQ_asc.push(pli(0LL, 1));
    while(!PQ_asc.empty()){
        auto p = PQ_asc.top();
        PQ_asc.pop();
        int curr = p.second;
        ll curr_dist = p.first;
        if (dist_asc[curr] < curr_dist) continue;
        for (auto pp: graph[curr]){
            int next = pp.first;
            ll weight = pp.second;
            if (height[curr] >= height[next]) continue;
            if (dist_asc[next] > dist_asc[curr] + weight){
                dist_asc[next] = dist_asc[curr] + weight;
                PQ_asc.push(pli(dist_asc[next], next));
            }
        }
    }
    
    dist_des[N] = 0LL;
    PQ_des.push(pli(0LL, N));
    while(!PQ_des.empty()){
        auto p = PQ_des.top();
        PQ_des.pop();
        int curr = p.second;
        ll curr_dist = p.first;
        if (dist_des[curr] < curr_dist) continue;
        for (auto pp: graph[curr]){
            int next = pp.first;
            ll weight = pp.second;
            if (height[curr] >= height[next]) continue;
            if (dist_des[next] > dist_des[curr] + weight){
                dist_des[next] = dist_des[curr] + weight;
                PQ_des.push(pli(dist_des[next], next));
            }
        }
    }
    
    ll ans = -INF;
    for (int i=2;i<N;i++){
        if (dist_asc[i] == INF || dist_des[i] == INF) continue;
        ans = max(ans, height[i]*E-(dist_asc[i] + dist_des[i])*D);
    }
    if (ans == -INF) printf("Impossible\n");
    else printf("%lld\n", ans);
    
	return 0;
}

