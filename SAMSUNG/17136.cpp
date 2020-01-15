// line 29에서 " a+n < 10 && b+n < 10 " 이라고 썼는데
// 이러면 5 + 5가 안 돌아감 -> " <= " 로 고치고 밑에 for문 범위 수

#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int grid[10][10];
int ans = 100;
int ret;
int paper[] = {0, 5, 5, 5, 5, 5};

void bt(int a, int b){
    if (b == 10){
        bt(a+1, 0);
        return;
    }
    if (a == 10){
        ans = min(ans, ret);
        return;
    }
    if (grid[a][b] == 0){
        bt(a, b+1);
        return;
    }
    else{
        for (int n = 5; n >= 1; n--){
            bool succ = true;
            if (paper[n] > 0 && a + n <= 10 && b + n <= 10){
                for (int x=a; x<a+n; x++){
                    for (int y=b; y<b+n;y++){
                        if (grid[x][y] == 0){
                            succ = false;
                            break;
                        }
                    }
                    if (!succ) break;
                }
                if (succ) {
                    for (int x=a; x<a+n;x++){
                        for (int y=b; y< b+n; y++){
                            grid[x][y] = 0;
                        }
                    }
                    paper[n]--;
                    ret++;
                    bt(a, b+1);
                    for (int x=a; x<a+n;x++){
                        for (int y=b; y<b+n; y++){
                            grid[x][y] = 1;
                        }
                    }
                    paper[n]++;
                    ret--;
                }
            }
        }
    }

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            scanf("%d", &grid[i][j]);
        }
    }

    bt(0, 0);
    if (ans == 100){
        printf("-1");
    }
    else{
        printf("%d", ans);
    }

}
