#include <bits/stdc++.h>
#define pii pair<int, int>
#define MAX 105

using namespace std;

int T;
int n;
pii pos[MAX];
int d[MAX][MAX];
bool visited[MAX];

int dist(pii a, pii b){
    int ai = a.first, aj = a.second, bi = b.first, bj = b.second;
    return (abs(ai - bi) + abs(aj - bj));
}

void DFS(int a){
    visited[a] = true;

    for (int i=0;i<=n+1;i++){
        if (i == a) continue;
        if (!visited[i] && d[a][i] <= 1000) DFS(i);
    }
}

int main(){DFS(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &T);
    for (int x=0;x<T;x++){
        memset(d, 0, sizeof(d));
        memset(visited, 0, sizeof(visited));
        scanf("%d", &n);
        int i_s, j_s, i_e, j_e;
        scanf("%d %d", &i_s, &j_s);
        pos[0] = pii(i_s, j_s);
        for (int i=1;i<=n;i++){
            int a, b;
            scanf("%d %d", &a, &b);
            pos[i] = pii(a, b);
        }
        scanf("%d %d", &i_e, &j_e);
        pos[n+1] = pii(i_e, j_e);
        for (int i=0;i<=n+1;i++){
            for (int j=0;j<=n+1;j++){
                if (i == j) continue;
                d[i][j] = dist(pos[i], pos[j]);
            }
        }

        DFS(0);

        if (visited[n+1]) printf("happy\n");
        else printf("sad\n");
    }
}
