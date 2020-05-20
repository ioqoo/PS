#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define pii pair<int, int>
#define MAX 10005
#define INF 987654321

using namespace std;

int T;
int N, D, S;
int a, b, s;
vector<pii> graph[MAX];
priority_queue<pii, vector<pii>, greater<pii>> PQ;
int dist[MAX];
bool visited[MAX];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d", &T);
	while(T>0){
	    T--;
	    
	    scanf("%d %d %d", &N, &D, &S);
	    memset(visited, 0, sizeof(visited));
	    fill(dist+1, dist+N+1, INF);
	    fill(graph+1, graph+N+1, vector<pii>());
	    
	    for (int i=0;i<D;i++){
	        scanf("%d %d %d", &a, &b, &s);
	        graph[b].push_back(pii(a, s));
        }
        
        dist[S] = 0;
        PQ.push(pii(0, S));
        while(!PQ.empty()){
            auto p = PQ.top();
            PQ.pop();
            int curr = p.second, curr_dist = p.first;
            if (visited[curr]) continue;
            visited[curr] = true;
            for (auto pp: graph[curr]){
                int next = pp.first, weight = pp.second;
                if (dist[next] > curr_dist + weight){
                    dist[next] = curr_dist + weight;
                    PQ.push(pii(dist[next], next));
                }
            }
        }
        
        int ans_cnt = 0;
        int ans_time = -1;
        for (int i=1;i<=N;i++){
            if (dist[i] == INF) continue;
            else{
                ans_cnt++;
                ans_time = max(ans_time, dist[i]);
            }
        }
        printf("%d %d\n", ans_cnt, ans_time);
	    
	    
    }

	return 0;
}

