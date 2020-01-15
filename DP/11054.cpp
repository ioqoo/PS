#include <bits/stdc++.h>
#define MAX 1005

using namespace std;

int N;
int num[MAX];
int dpf[MAX], dpr[MAX], dpt[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        scanf("%d", &num[i]);
    }

    for (int i=1;i<=N;i++){
        int curr_max = 0;
        for (int j=0;j<i;j++){
            if (num[j] < num[i]){
                curr_max = max(curr_max, dpf[j]);
            }
        }
        dpf[i] = curr_max + 1;
    }

    for (int i=N;i>=1;i--){
        int curr_max = 0;
        for (int j=N+1;j>i;j--){
            if (num[j] < num[i]){
                curr_max = max(curr_max, dpr[j]);
            }
        }
        dpr[i] = curr_max + 1;
    }
    for (int i=1;i<=N;i++){
        dpt[i] = dpf[i] + dpr[i];
    }
//    for (int i=1;i<=N;i++){
//        printf("%d ", dpf[i]);
//    }
//    printf("\n");
//    for (int i=1;i<=N;i++){
//        printf("%d ", dpr[i]);
//    }
//    printf("\n");
    printf("%d", *max_element(dpt+1, dpt+N+1) - 1);
}
