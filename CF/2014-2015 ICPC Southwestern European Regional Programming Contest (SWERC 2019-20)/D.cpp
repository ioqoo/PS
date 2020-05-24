#include <bits/stdc++.h>

const int MAX = 10005;
using namespace std;

int N, M;
vector<int> graph[MAX];
bool visited[MAX];
bool finished[MAX];
int pre[MAX];
int want[MAX];
int book[MAX];
int cnt;

void dfs(int curr){
//    printf("curr : %d\n", curr);
//    for (int i=0;i<N;i++){
//        printf("%d ", finished[i]);
//    }
//    printf("\n");
    visited[curr] = true;
    for (int next: graph[curr]){
        if (book[next] == want[curr]){
            pre[next] = curr;
            dfs(next);
        }
        else{
            bool succ = true;
            for (int i=curr;i!=next;i=pre[i]){
                if (book[i] != i){
                    succ = false;
                    break;
                }
            }
            if (book[next] != next) succ = false;
            if (succ){
                for (int i=curr;i!=next;i=pre[i]){
                    swap(book[i], book[pre[i]]);
                }
                swap(book[next], book[curr]);
            }
        }
    }
//    finished[curr] = true;
    
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d %d", &N, &M);
    int u, v;
    for (int i=0;i<M;i++){
        scanf("%d %d", &u, &v);
        want[u] = v;
        graph[u].push_back(v);
//        graph[v].push_back(u);
    }
    for (int i=0;i<N;i++){
        book[i] = i;
    }
    for (int i=0;i<N;i++){
        if (book[i] == i) dfs(i);
    }
    for (int i=0;i<N;i++){
        printf("%d ", book[i]);
//        if (book[i] == i) {
//            printf("NO\n");
//            return 0;
//        }
    }
//    printf("YES\n");
    
    

    return 0;
}



