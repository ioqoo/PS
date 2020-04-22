#include <iostream>
#include <vector>
#include <queue> 
#include <cstring>
#include <algorithm>

#define pii pair<int, int>
#define MAX 20005
#define INF 987654321

using namespace std;

int N, M;
vector<int> graph[MAX];
int dist[MAX];
bool visited[MAX];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d %d", &N, &M);
	int u, v;
	for (int i=0;i<M;i++){
	    scanf("%d %d", &u, &v);
	    graph[u].push_back(v);
	    graph[v].push_back(u);
    }
    
    fill(dist+1, dist+N+1, INF);
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    PQ.push(pii(0, 1));
    
    while(!PQ.empty()){
        auto p = PQ.top();
        PQ.pop();
        int curr = p.second, curr_dist = p.first;
        if (visited[curr]) continue;
        visited[curr] = true;
        for (int next: graph[curr]){
            if (dist[next] > curr_dist + 1){
                dist[next] = curr_dist + 1;
                PQ.push(pii(curr_dist+1, next));
            }
        }
    }
    
    int ans_num = 0, ans_dist = 0, ans_cnt = 0;
    
    for (int i=2;i<=N;i++){
        if (dist[i] > ans_dist){
            ans_num = i;
            ans_dist = dist[i];
            ans_cnt = 1;
        }
        else if (dist[i] == ans_dist){
            ans_cnt++;
        }
    }
    
    printf("%d %d %d", ans_num, ans_dist, ans_cnt);

	return 0;
}

