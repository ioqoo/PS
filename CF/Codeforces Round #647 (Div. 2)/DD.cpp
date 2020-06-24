#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
const int INF = 987654321;
const int MAX = 500005;
using namespace std;

vector<int> graph[MAX];
int desire[MAX];
vector<pii> edge;
vector<int> ans;
int indeg[MAX];
int dist[MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N, M;
    scanf("%d %d", &N, &M);
    
    for (int i=0;i<M;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        edge.push_back({u, v});
    }
    for (int i=1;i<=N;i++){
        scanf("%d", &desire[i]);
    }
    
    for (auto p: edge){
        int u = p.first, v = p.second;
        if (desire[u] > desire[v]) swap(u, v);
        else if (desire[u] == desire[v]) {
            if (u > v) swap(u, v);
        }
        graph[u].push_back(v);
        indeg[v]++;
    }
    
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    for (int i=1;i<=N;i++){
        if (indeg[i] == 0) {
            Q.push({desire[i], i});
            dist[i] = 1;
        }
    }
    
//    memset(dist, 0x3f3f3f3f, INF);
    for (int i=0;i<N;i++){
        if (Q.empty()) {
            printf("-1\n");
            return 0;
        }
        int curr = Q.top().second; Q.pop();
        ans.push_back(curr);
        for (int next: graph[curr]){
            dist[next] = max(dist[next], dist[curr] + 1);
            if (--indeg[next] == 0){
                Q.push({desire[next], next});
            }
        }
    }
    if (ans.size() < N) {
        printf("-1\n");
    }
    else {
        for (int i=1;i<=N;i++){
            if (dist[i] != desire[i]){
                printf("-1\n");
                return 0;
            }
        }
        for (int n: ans){
            printf("%d ", n);
        }
    }
    

    return 0;
}



