#include <iostream>
#include <queue>
#include <cstring>

#define MAX 303
#define pii pair<int, int>

using namespace std;

int T, I;
int Si, Sj, Di, Dj;
bool visited[MAX][MAX];
int di[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dj[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dist[MAX][MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &T);
    while(T>0){
        T--;
        
        memset(visited, 0, sizeof(visited));
        memset(dist, 0, sizeof(dist));
        scanf("%d", &I);
        scanf("%d %d", &Si, &Sj);
        scanf("%d %d", &Di, &Dj);
        queue<pii> Q;
        Q.push({Si, Sj});
        visited[Si][Sj] = true;
        while(!Q.empty()){
            auto p = Q.front();
            Q.pop();
            int ci = p.first, cj = p.second;
            for (int d=0;d<8;d++){
                int ni = ci + di[d], nj = cj + dj[d];
                if (ni < 0 || ni >= I || nj < 0 || nj >= I) continue;
                if (visited[ni][nj]) continue;
                dist[ni][nj] = dist[ci][cj] + 1;
                visited[ni][nj] = true;
                Q.push({ni, nj});
            }
        }
        printf("%d\n", dist[Di][Dj]);
    }
    

    return 0;
}



