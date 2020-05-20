#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second

using namespace std;

int grid[9][9];
vector<pii> blank;
bool done;

void bt(int pos){
//    for (int i=0;i<9;i++){
//        for (int j=0;j<9;j++){
//            printf("%d ", grid[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
    if (done) return;
    if (pos >= blank.size()) {
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        done = true;
        return;
    }

    bool poss[10];
    fill(poss, poss+10, 1);
    int x = blank[pos].fi, y = blank[pos].se;
    for (int i=0;i<9;i++){
        if (i == x) continue;
        poss[grid[i][y]] = false;
    }
    for (int j=0;j<9;j++){
        if (j == y) continue;
        poss[grid[x][j]] = false;
    }
    for (int bi=3*(x/3);bi<3*(x/3 + 1);bi++){
        for (int bj=3*(y/3);bj<3*(y/3 + 1);bj++){
            if (bi == x && bj == y) continue;
            poss[grid[bi][bj]] = false;
        }
    }
    bool succ = false;
    for (int i=1;i<=9;i++){
        if (poss[i]) {
            grid[x][y] = i;
            bt(pos + 1);
            grid[x][y] = 0;
        }
    }
    if (!succ) return;
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            int temp;
            scanf("%d", &temp);
            if (temp == 0) blank.push_back(pii(i, j));
            grid[i][j] = temp;
        }
    }

    bt(0);
}
