#include <bits/stdc++.h>

#define ll long long
const int MAX = 53;
using namespace std;

int N, M;
int grid[MAX][MAX];


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    scanf("%d", &t);
    // cin >> t;
    while(t--){
        scanf("%d %d", &N, &M);
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                scanf("%d", &grid[i][j]);
            }
        }
        int rownotcnt = 0, colnotcnt = 0;
        for (int i=0;i<N;i++){            
            for (int j=0;j<M;j++){
                if (grid[i][j] == 1) {
                    rownotcnt++;
                    break;
                }
            }
        }
        for (int j=0;j<M;j++){
            for (int i=0;i<N;i++){
                if (grid[i][j] == 1){
                    colnotcnt++;
                    break;
                }
            }
        }
        rownotcnt = N - rownotcnt;
        colnotcnt = M - colnotcnt;
        int minimum = min(rownotcnt, colnotcnt);
        if (minimum%2){ // odd 
            printf("Ashish\n");
        }
        else{
            printf("Vivek\n");
        }
    }

    return 0;
}



