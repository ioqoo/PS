#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

#define MAX 100003
#define INF 987654321
#define pii pair<int, int>

using namespace std;

int V, E;
int order[MAX];
vector<int> graph[MAX];
set<pii> ans;
int cnt;

int dfs(int curr, int parent){
    order[curr] = ++cnt;
    int ret = order[curr];
    
    for (int next: graph[curr]){
        if (next == parent) continue;
        
        if (!order[next]){
            int low = dfs(next, curr);
            if (order[curr] < low) {
                int a = min(curr, next), b = max(curr, next);
                ans.insert(pii(a, b));
            }
            ret = min(ret, low);
        }
        else{
            ret = min(ret, order[next]);
        }
    } 
    
    return ret;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d %d", &V, &E);
    if (V==1) {
        printf("0\n");
        return 0;
    }
    for (int i=0;i<E;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    dfs(1, 0);
    
    
    printf("%d\n", ans.size());
    for (auto it=ans.begin();it!=ans.end();it++){
        auto p = *it;
        printf("%d %d\n", p.first, p.second);
    }
    
    
    return 0;
} 
