#include <bits/stdc++.h>

#define pii pair<int, int>
const int INF = 0x3f3f3f3f;
const int MAX = 100005;
using namespace std;

int N, M;    
int pre[103];
bool visited[103];
vector<int> flo[MAX]; // flo[i] : i층을 갈 수 있는 엘리베이터 번호들 
vector<int> ele[102]; // ele[i] : i번 엘리베이터가 갈 수 있는 층수들

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    scanf("%d %d", &N, &M);
    
    for (int i=1;i<=M;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        while(x<=N){
            flo[x].push_back(i);
            ele[i].push_back(x);
            x += y;
        }
    }
    int S, E;
    scanf("%d %d", &S, &E);
    
    queue<int> Q;
    for (int n: flo[S]){
        Q.push(n);
        visited[n] = true;
    }
    
    int last = 0;
    bool succ = false;
    while(!Q.empty()){
        int curr = Q.front(); Q.pop();
        for (int f: ele[curr]){
            if (f == E) {
                last = curr;
                succ = true;
                break;
            }
            for (int next: flo[f]){
                if (!visited[next]) {
                    Q.push(next);
                    visited[next] = true;
                    pre[next] = curr;
                }
            }
        }
        if (succ) break;
    }
    
    vector<int> path;
    
    for (int i=last;i!=0;i=pre[i]){
        path.push_back(i);
    }
    
    int size = path.size();
    if (size == 0) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", size);
    for (int i=size-1;i>=0;i--){
        printf("%d\n", path[i]);
    }
    
    return 0;
}



