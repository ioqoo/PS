#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <stack>
 
#define ll long long
#define pii pair<int, int>
#define MAX 1505
#define INF 987654321
#define MOD 1000000007

using namespace std;

int N, M;
vector<pii> graph[MAX];
vector<pii> graph_rev[MAX];
vector<pii> edges;
ll to[MAX], from[MAX];
ll ans[MAX];
vector<int> DAGout[MAX];
vector<int> DAGin[MAX];
int DAGmat[MAX][MAX];
bool visited[MAX];
int dist[MAX];
stack<int> st;
queue<int> q;

// fix된 S에서 dijkstra를 돌릴 때 사용한 edge들을 모으면 무조건 DAG가 된다.
// 그 DAG들에 포함된 edge들은 S에서 출발해서 다른 모든 점들로 가는 최단경로에 포함되는 edge들이다. 

// 200305 미완성 

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d %d", &N, &M);
	for (int i=0;i<M;i++){
	    int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(pii(v, w));
        graph_rev[v].push_back(pii(u, w));
        edges.push_back(pii(u, v));
    }
    
    for (int S=1;S<=N;S++){
        fill(DAGout+1, DAGout+N+1, vector<int> ());
        fill(DAGin+1, DAGin+N+1, vector<int> ());
        memset(DAGmat, 0, sizeof(DAGmat));
        memset(visited, 0, sizeof(visited));
        fill(dist+1, dist+N+1, INF);
        
        priority_queue<pii, vector<pii>, greater<pii>) PQ;
        st.clear();
        q.clear();
        dist[S] = 0;
        PQ.push(pii(0, S));
        while(!PQ.empty()){
            auto p = PQ.top();
            PQ.pop();
            int curr = p.second, curr_dist = p.fist;
            if (visited[curr]) continue;
            visitec[curr] = true;
            for (auto pp: graph[curr]){
                int next = pp.first, weight = pp.second;
                if (dist[next] > curr_dist + weight){
                    dist[next] = curr_dist + weight;
                    PQ.push(pii(dist[next], next));
                }
            }
        }
        
        
        
        
        
    }
    
    

	return 0;
}

