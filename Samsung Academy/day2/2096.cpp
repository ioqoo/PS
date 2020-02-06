#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int N;
int window[2][3][2];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);

    for (int x=0;x<N;x++){
        int curr_row[3] = {0};
        scanf("%d %d %d", &curr_row[0], &curr_row[1], &curr_row[2]);

        if (x==0) {
            for (int i=0;i<3;i++){
                window[0][i][0] = curr_row[i];
                window[1][i][0] = curr_row[i];
            }
        }
        else{
            window[0][0][1] = max(window[0][0][0], window[0][1][0]) + curr_row[0];
            window[0][1][1] = max(window[0][0][0], max(window[0][1][0], window[0][2][0])) + curr_row[1];
            window[0][2][1] = max(window[0][1][0], window[0][2][0]) + curr_row[2];

            window[1][0][1] = min(window[1][0][0], window[1][1][0]) + curr_row[0];
            window[1][1][1] = min(window[1][0][0], min(window[1][1][0], window[1][2][0])) + curr_row[1];
            window[1][2][1] = min(window[1][1][0], window[1][2][0]) + curr_row[2];

            for (int j=0;j<3;j++){
                window[0][j][0] = window[0][j][1];
                window[1][j][0] = window[1][j][1];
            }
        }
    }


    int M = max(window[0][0][0], max(window[0][1][0], window[0][2][0]));
    int m = min(window[1][0][0], min(window[1][1][0], window[1][2][0]));
    printf("%d %d\n", M, m);


    return 0;
}
