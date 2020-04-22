#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>

#define pii pair<int, int>
#define MAX 1005
#define INF 987654321

using namespace std;

int T;
int R, C;
string row;
int grid[MAX][MAX];
int dist[MAX*MAX];
bool visited[MAX*MAX];

vector<int> graph[MAX*MAX];
int node_num = 1;
int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	
	while(T>0){
	    T--;
	    node_num = 1;
	    memset(grid, 0, sizeof(grid));
	    memset(visited, 0, sizeof(visited));
	    priority_queue<pii, vector<pii>, greater<pii>> PQ1;
        priority_queue<pii, vector<pii>, greater<pii>> PQ2;
	    
	    cin >> C >> R;
	    for (int i=0;i<R;i++){
	        cin >> row;
	        for (int j=0;j<C;j++){
	            if (row[j] == '.'){
	                grid[i][j] = node_num;
	                node_num++;
                }
                else{
                    grid[i][j] = 0;
                }
            }
        }
        
        if (node_num <= 2){
            cout << "Maximum rope length is 0.\n";
            continue;
        }
        
        for (int i=1;i<node_num;i++){
            graph[i].clear();
        }
        
        
        for (int i=0;i<R;i++){
            for (int j=0;j<C;j++){
                if (grid[i][j]){
                    for (int d=0;d<4;d++){
                        int ni = i + di[d], nj = j + dj[d];
                        if (ni < 0 || ni >= R || nj < 0 || nj >= C || grid[ni][nj] == 0) continue;
                        graph[grid[i][j]].push_back(grid[ni][nj]);
                    }
                }
            }
        }
        
//        for (int i=0;i<R;i++){
//            for (int j=0;j<C;j++){
//                cout << grid[i][j] << " ";
//            }
//            cout << endl;
//        }
        
        fill(dist+1, dist+node_num, INF);
        dist[1] = 0;
        PQ1.push(pii(0, 1));
        while (!PQ1.empty()){
            auto p = PQ1.top();
            PQ1.pop();
            int curr = p.second, curr_dist = p.first;
            if (visited[curr]) continue;
            visited[curr] = true;
            for (int next: graph[curr]){
                if (dist[next] > curr_dist + 1){
                    dist[next] = curr_dist + 1;
                    PQ1.push(pii(dist[next], next));
                }
            }
        }
        int S, max_dist = -1;
        for (int i=1;i<node_num;i++){
            if (max_dist < dist[i]) {
                max_dist = dist[i];
                S = i;
            }
        }
        
//        for (int i=1;i<node_num;i++){
//            cout << dist[i] << " ";
//        }
//        cout << endl;
        
        memset(visited, 0, sizeof(visited));
        fill(dist+1, dist+node_num, INF);
        dist[S] = 0;
        PQ2.push(pii(0, S));
        while(!PQ2.empty()){
            auto p = PQ2.top();
            PQ2.pop();
            int curr = p.second, curr_dist = p.first;
            if (visited[curr]) continue;
            visited[curr] = true;
            for (int next: graph[curr]){
                if (dist[next] > curr_dist + 1){
                    dist[next] = curr_dist + 1;
                    PQ2.push(pii(dist[next], next));
                }
            }            
        }
//        for (int i=1;i<node_num;i++){
//            cout << dist[i] << " ";
//        }
//        cout << endl;
        
        int ans = -1;
        for (int i=1;i<node_num;i++){
            ans = max(ans, dist[i]);
        }
        cout << "Maximum rope length is " << ans << ".\n";
    }

	return 0;
}

