#include <bits/stdc++.h>

#define pii pair<int, int>
#define ll long long
const int INF = 987654321;
const int MAX = 500005;
using namespace std;

vector<int> graph[MAX];
int desire[MAX];
bool visited[MAX];
vector<int> ans;
set<pii> S;

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
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
//    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    
    int st = INF;
    for (int i=1;i<=N;i++){
        scanf("%d", &desire[i]);
        S.insert({desire[i], i});
    }
    
    for (auto it=S.begin();it!=S.end();it++){
        auto p = *it;
        int curr_topic = p.first, curr = p.second;
        if (visited[curr]) continue;
        visited[curr] = true;
        ans.push_back(curr);
        for (int next: graph[curr]){
            if (visited[next]){
                if (curr_topic == desire[next]){
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }
    
    for (int n: ans){
        printf("%d ", n);
    }
    
    
    
    

    return 0;
}




