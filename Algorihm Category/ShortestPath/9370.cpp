#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define pii pair<int, int>
#define MAX 2005
#define INF 987654321

using namespace std;

int X, N, M, T;
int S, G, H;
int a, b, d;
vector<pii> graph[MAX];
vector<int> candi;
vector<int> ans;
int dist[MAX];
bool visited[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &X);
    for (int x=0;x<X;x++){
        memset(visited, 0, sizeof(visited));
        candi.clear();
        ans.clear();
        fill(graph, graph+MAX, vector<pii> ());
        
        scanf("%d %d %d", &N, &M, &T);
        scanf("%d %d %d", &S, &G, &H);
        for (int i=0;i<M;i++){
            scanf("%d %d %d", &a, &b, &d);
            graph[a].push_back(pii(b, d));
            graph[b].push_back(pii(a, d));
        }
        int temp;
        for (int i=0;i<T;i++){
            scanf("%d", &temp);
            candi.push_back(temp);
        }
        sort(candi.begin(), candi.end());
        
        fill(dist, dist+MAX, INF);
        dist[S] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> PQ;
        PQ.push(pii(0, S));
        while(!PQ.empty()){
            int curr = PQ.top().second, curr_dist = PQ.top().first;
            PQ.pop();
            if (visited[curr]) continue;
            visited[curr] = true;
            for (auto p: graph[curr]){
                int next = p.first, weight = p.second;
                if (dist[next] > curr_dist + weight){
                    dist[next] = curr_dist + weight;
                    PQ.push(pii(dist[next], next));
                }
            }
        }
        
        for (int n: candi){
            bool succ = false;
            memset(visited, 0, sizeof(visited));
            queue<int> Q;
            Q.push(n);
            while(!Q.empty()){
                int curr = Q.front();
                Q.pop();
                for (auto p: graph[curr]){
                    int next = p.first, weight = p.second;
                    if (dist[curr] - weight == dist[next]){
                        if ( (next == G && curr == H) || (next == H && curr == G) ){
                            succ = true;
                            break;
                        }
                        if (!visited[next]) {
                            Q.push(next);
                            visited[next] = true;
                        }
                    }
                }
                if (succ) {
                    ans.push_back(n);
                    break;
                }
            }
        }
        
        for (int n: ans){
            printf("%d ", n);
        }
        printf("\n");
        
        
    }
    
    

    return 0;
}

