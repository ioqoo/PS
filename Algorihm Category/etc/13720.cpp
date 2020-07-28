#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N;
    scanf("%d", &N);
    if (N == 2) {
        printf("-1\n");
        return 0;
    }
    int cnt = 0;
    int jump = N*(N-1)/2 - (N-1);
    int downjump = 0;
    if (N%2 ==0) {
        for (int i=1;i<=N;i++){
            for (int j=1;j<=N;j++){
                if (i!=N){
                    if (j!=N){
                        printf("%d ", ++cnt);
                    }
                    else{
                        cnt += jump;
                        if (i==1) downjump = cnt;
                        printf("%d ", cnt);
                    }
                }
                else{
                    if (j==1){
                        cnt = 1+(N-2)*downjump + downjump*jump;
                        printf("%d ", cnt);
                    }
                    else if (j!=N){
                        printf("%d ", ++cnt);
                    }
                    else{
                        cnt += jump;
                        printf("%d ", cnt);
                    }
                }
            }
            printf("\n");
        }
    }
    else{
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                printf("%d ", ++cnt);
            }
            printf("\n");
        }
    }

    return 0;
}



