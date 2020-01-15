// 개고생한 이유 : Line 23, 35에 nj 범위 N으로 씀

#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int N, M, D;
vector<int> grid[15];
int ans = 0;
bool eli[15][15];

int dist(int i1, int j1, int i2, int j2){
    return abs(i1 - i2) + abs(j1 - j2);
}

vector<pii> targets(int level, int pos, int range){
    vector<pii> ret;
    for (int i=1;i<=range;i++){
        for (int j=range - 1;j >= 0;j--){
            if (i + j == range){
                int ni = N - i - level, nj = pos - j;
                if (0 <= ni && ni < N && 0 <= nj && nj < M && grid[ni][nj] == 1){
                    ret.push_back(pii(ni, nj));
                }

            }
        }
    }
    for (int i=range-1;i>=1;i--){
        for (int j=1;j<range;j++){
            if (i+j == range){
                if (i + j == range){
                    int ni = N - i - level, nj = pos + j;
                    if (0 <= ni && ni < N && 0 <= nj && nj < M && grid[ni][nj] == 1){
                        ret.push_back(pii(ni, nj));
                    }
                }
            }
        }
    }
/

    return ret;
}

void bt(int i, vector<int> ch){
    if (ch.size() > 3){
        return;
    }
    if (ch.size() == 3){
        memset(eli, 0, sizeof(eli));
        int ret = 0;
        for (int x = 0;x<N;x++){
            vector<pii> kill;
            for (auto p: ch){
                for (int d=1;d<=D;d++){
                    bool succ = false;
                    vector<pii> tg = targets(x, p, d);
                    for (auto pi: tg){
                        int m = pi.first, n = pi.second;
                        if (!eli[m][n]){
                            kill.push_back(pii(m, n));
                            succ = true;
                            break;
                        }
                    }
                    if (succ) break;
                }
            }
            for (auto p: kill){
                if (!eli[p.first][p.second]){
                    eli[p.first][p.second] = true;
                    ret++;
                }
            }
/       }
        ans = max(ans, ret);

    }

    for (int j=i+1;j<M;j++){
        ch.push_back(j);
        bt(j, ch);
        ch.pop_back();
    }
}



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d %d", &N, &M, &D);
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            int temp;
            scanf("%d", &temp);
            grid[i].push_back(temp);
        }
    }
    for (int i=0;i<M;i++){
        vector<int> ch;
        ch.push_back(i);
        bt(i, ch);
        ch.pop_back();
    }

    printf("%d\n", ans);

}
