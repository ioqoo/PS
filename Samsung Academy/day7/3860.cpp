#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define MAX 905
#define INF 987654321
#define pii pair<int, int>

using namespace std;

int W, H, G, E;
int node;
int grid[33][33];
int dist[MAX];
bool stone[33][33]; // true : unavailable 
bool ghost[33][33];
vector<pii> graph[MAX];
int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

int pii_to_node(pii A){
    return (A.first * W) + (A.second);
}

pii node_to_pii(int node){
    return pii(node / W, node % W);
}

bool range_check(int i, int j){
    if (0 <= i && i < H && 0 <= j && j < W) return true;
    else return false;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    while(true){
        memset(grid, 0, sizeof(grid));
        memset(stone, 0, sizeof(stone));
        memset(ghost, 0, sizeof(ghost));
        
        scanf("%d %d", &W, &H);
        if (W==0 && H==0) break;
        
        for (int i=0;i<W*H;i++){
            graph[i].clear();
        }
        for (int i=0;i<W*H;i++){
            dist[i] = INF;
        }
        
        scanf("%d", &G);
        for (int g=0;g<G;g++){
            int i, j;
            scanf("%d %d", &j, &i);
            stone[i][j] = true;
        }
        
        scanf("%d", &E);
        for (int e=0;e<E;e++){
            int i1, j1, i2, j2, c;
            scanf("%d %d %d %d %d", &j1, &i1, &j2, &i2, &c);
            ghost[i1][j1] = true;
            int node_s = pii_to_node(pii(i1, j1));
            int node_e = pii_to_node(pii(i2, j2));
            graph[node_s].push_back(pii(node_e, c));
        }
        
        for (int i=0;i<H;i++){
            for (int j=0;j<W;j++){
                if (i==H-1 && j==W-1) continue;
                if (ghost[i][j]) continue; // 귀신 구멍에서 인접한 잔디에 추가로 간선 만들면 X 
                int curr_node = pii_to_node(pii(i, j));
                for (int d=0;d<4;d++){
                    int ni = i + di[d], nj = j + dj[d];
                    if (!range_check(ni, nj)) continue;
                    if (stone[ni][nj]) continue;
                    
                    int next_node = pii_to_node(pii(ni, nj));
                    graph[curr_node].push_back(pii(next_node, 1));
                }
            }
        }
        
        dist[0] = 0;
        
        bool negcycle = false;
        for (int n=1;n<=W*H;n++){
            for (int curr=0;curr<W*H;curr++){
                for (auto p: graph[curr]){
                    int next = p.first, weight = p.second;
                    if (dist[curr] != INF && dist[next] > dist[curr] + weight){
                        dist[next] = dist[curr] + weight;
                        
                        if (n == W*H) negcycle = true;
                    }
                }
            }
        }
                
        if (negcycle) {
            printf("Never\n");
            continue;
        }
        if (dist[W*H-1] == INF) {
            printf("Impossible\n");
        }
        else{
            printf("%d\n", dist[W*H-1]);
        }
        
        
    }
    
    return 0;
} 
