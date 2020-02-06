#include <bits/stdc++.h>
#define MAX 100005
#define ll long long

using namespace std;

int ind[MAX], out[MAX];
vector<int> graph[MAX];
bool visited[MAX];
int M;
int case_num = 1;
bool istree = true;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);


    while(true){
        int u, v;
        scanf("%d %d", &u, &v);
        if (u < 0 && v < 0) return 0;

        if (u == 0 && v == 0) {
            int rootcnt = 0;
            for (int i=1;i<=M;i++){
                if (ind[i] == 0){
                    rootcnt++;
                }
            }
            if (rootcnt != 1){
                istree = false;
            }

            int nonrootcnt = 0;
            for (int i=1;i<=M;i++){
                if (ind[i] == 1){
                    nonrootcnt++;
                }
            }
            if (nonrootcnt != M-1){
                istree = false;
            }



            if (istree) printf("Case %d is a tree.\n", case_num);
            else printf("Case %d is not a tree.\n", case_num);
            case_num++;
            istree = true;
            memset(ind, 0, sizeof(ind));
            memset(out, 0, sizeof(out));
            memset(visited, 0, sizeof(visited));
            for (int i=1;i<=M;i++){
                graph[i].clear();
            }
            M = 0;
            continue;
        }

        M = max(M, max(u, v));
        ind[v]++; out[u]++;
        graph[u].push_back(v);
    }


    return 0;
}
