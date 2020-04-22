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

void make_tree(int curr){
    visited[curr] = true;
    for (int next: graph[curr]){
        if (visited[next]) continue;
        dist[next] = dist[curr] + 1;
        make_tree(next);
    }
    return;
}


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
        
        for (int i=1;i<MAX*MAX;i++){
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
        
        memset(visited, 0, sizeof(visited));
        memset(dist, 0, sizeof(dist));
        make_tree(1);
        
        int S, max_dist = -1;
        for (int i=1;i<node_num;i++){
            if (max_dist < dist[i]){
                max_dist = dist[i];
                S = i;
            }
        }
        
        memset(visited, 0, sizeof(visited));
        memset(dist, 0, sizeof(dist));
        make_tree(S);
        int ans = -1;
        for (int i=1;i<node_num;i++){
            ans = max(ans, dist[i]);
        }
        cout << "Maximum rope length is " << ans << ".\n";
        
    }

	return 0;
}

