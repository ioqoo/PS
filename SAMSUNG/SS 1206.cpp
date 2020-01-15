#include <bits/stdc++.h>

using namespace std;

int T = 10;
int height[1005];
int N;
int dx[4] = {-2, -1, 1, 2};

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    for (int x=1;x<=T;x++){
        scanf("%d", &N);
        for (int i=0;i<N;i++){
            scanf("%d", &height[i]);
        }
        int ans = 0;
        for (int i=2;i<N-2;i++){
            int curr = height[i];
            int M = -1;
            for (int d=0;d<4;d++){
                M = max(M, height[i+dx[d]]);
            }
            ans += max(0, curr - M);
        }
        printf("#%d %d\n", x, ans);
    }
}
