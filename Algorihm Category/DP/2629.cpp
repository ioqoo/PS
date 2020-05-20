#include <bits/stdc++.h>

using namespace std;

int N, Q;
int a[33];
bool visited[33][40005];

void dfs(int pos, int weight){
    if (pos > N) return;
    if (visited[pos][weight]) return;
    visited[pos][weight] = true;
    int next = a[pos];
    dfs(pos+1, weight+next);
    dfs(pos+1, weight);
    dfs(pos+1, abs(weight-next));
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        scanf("%d", &a[i]);
    }
    dfs(0, 0);
    
//    for (int i=0;i<=N;i++){
//        for (int j=0;j<=10;j++){
//            printf("%d ", visited[i][j]);
//        }
//        printf("\n");
//    }
    
    scanf("%d", &Q);
    for (int i=0;i<Q;i++){
        int q;
        scanf("%d", &q);
        if (visited[N][q]) printf("Y ");
        else printf("N ");
    }

    return 0;
}



