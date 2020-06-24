#include <bits/stdc++.h>

#define pii pair<int, int>
const int MAX = 10005;
const int INF = 0x3f3f3f3f;
using namespace std;

int N, M;
int dist[MAX];
map<pii, vector<int>> mp;
priority_queue<pii, vector<pii>, greater<pii>> PQ;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d %d", &N, &M);
    memset(dist, INF, sizeof(INF));
    
    int E;
    for (int i=1;i<=N;i++){
        int cost;
        scanf("%d", &cost);
        dist[i] = cost;
        PQ.push({cost, i});
    }
    
    for(int i=0;i<M;i++){
        int a, x, y;
        scanf("%d %d %d", &a, &x, &y);
        if (x>y) swap(x, y);
        mp[{x, y}].push_back(a);
    }
    
    int last = -1;
    while(!PQ.empty()){
        auto p = PQ.top(); PQ.pop();
        int currdist = p.first, curr = p.second;
        if (curr == last) continue;
        if (curr == 1){
            printf("%d\n", currdist);
            break;
        }
        int a = min(last, curr);
        int b = max(last, curr);
//        printf("%d %d\n", a,b );
        if (mp.count({a,b})){
            for (int c: mp[{a,b}]){
//                printf("c: %d\n", c);
                if (dist[c] > dist[a] + dist[b]){
                    dist[c] = dist[a] + dist[b];
//                    printf("dist[c] : %d / dist[a] : %d / dist[b] : %d\n", dist[c], dist[a], dist[b]);
                    PQ.push({dist[c], c});
                }
            }
        }
        last = curr;
    }
    

    return 0;
}



