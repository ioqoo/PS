#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

#define MAX 505
#define pii pair<int, int>

using namespace std;

int T;
int N, M;
int num[MAX];
vector<pii> change;
vector<int> graph[MAX];
bool adj[MAX][MAX];
int indegree[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &T);
    while(T>0){
        T--;
        
        change.clear();
        fill(graph+1, graph+N+1, vector<int> ());
        memset(adj, 0, sizeof(adj));
        memset(indegree, 0, sizeof(indegree));
        scanf("%d", &N);
        for (int i=0;i<N;i++){
            scanf("%d", &num[i]);
        }
        scanf("%d", &M);
        int u, v;
        for (int i=0;i<M;i++){
            scanf("%d %d", &u, &v);
            change.push_back(pii(u, v));
        }
        for (int i=0;i<N-1;i++){
            for (int j=i+1;j<N;j++){
                int a = num[i], b = num[j];
                adj[a][b] = true;
            }
        }
        
        for (auto p: change){
            int a = p.first, b = p.second;
            if (adj[a][b]){
                adj[a][b] = false;
                adj[b][a] = true;
            }
            else if (adj[b][a]){
                adj[b][a] = false;
                adj[a][b] = true;
            }
        }
        
        for (int i=1;i<=N;i++){
            for (int j=1;j<=N;j++){
                if (adj[i][j]) {
                    graph[i].push_back(j);
                    indegree[j]++;
                }
            }
        }
        queue<int> Q;
        for (int i=1;i<=N;i++){
            if (indegree[i] == 0) {
                Q.push(i);
            }
        }
        
        bool imposs = false;
        bool multi = false;
        vector<int> ans;
        for (int i=0;i<N;i++){
            if (Q.empty()){
                imposs = true;
                break;
            }
            if (Q.size() >= 2){
                multi = true;
                break;
            }
            int curr = Q.front();
            Q.pop();
            ans.push_back(curr);
            for (int next: graph[curr]){
                indegree[next]--;
                if (indegree[next] == 0){
                    Q.push(next);
                }
            }
        }
        if (imposs) printf("IMPOSSIBLE\n");
        else if (multi) printf("?\n");
        else{
            for (int curr: ans){
                printf("%d ", curr);
            }
            printf("\n");
        }
        
    }

    return 0;

}
