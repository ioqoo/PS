// https://www.acmicpc.net/problem/18232

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N, M, S, E;
vector<int> graph[300003];
bool visited[300003];
int depth[300003];
queue<int> q;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d %d %d", &N, &M, &S, &E);
    for (int i=0;i<M;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    q.push(S);
    visited[S] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if (u == E){
            break;
        }
        if (u > 1 && !visited[u-1]){
            visited[u-1] = true;
            depth[u-1] = depth[u] + 1;
            q.push(u-1);
        }
        if (u < N && !visited[u+1]){
            visited[u+1] = true;
            depth[u+1] = depth[u] + 1;
            q.push(u+1);
        }
        if (!graph[u].empty()){
            for (int i=0;i<graph[u].size();i++){
                int next = graph[u][i];
                if (!visited[next]){
                visited[next] = true;
                depth[next] = depth[u] + 1;
                q.push(next);
                }
            }
        }
    }
    printf("%d\n", depth[E]);

    return 0;

}
