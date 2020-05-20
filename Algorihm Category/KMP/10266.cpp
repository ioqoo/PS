#include <bits/stdc++.h>

const int MAX = 360000;

using namespace std;

int N;
int H[2*MAX], D[MAX];
int fail[MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        int temp;
        scanf("%d", &temp);
        H[temp] = H[temp+MAX] = 1;
    }
    for (int i=0;i<N;i++){
        int temp;
        scanf("%d", &temp);
        D[temp] = 1;
    }
    
    for (int i=1,j=0;i<MAX;i++){
        while(j>0 && D[i] != D[j]) j = fail[j-1];
        if (D[i] == D[j]) fail[i] = ++j;
    }
    
    for (int i=0,j=0;i<MAX*2;i++){
        while(j>0 && H[i] != D[j]) j = fail[j-1];
        if (H[i] == D[j]){
            if (j == MAX-1){
                printf("possible\n");
                return 0;
            }
            else j++;
        }
    }
    printf("impossible\n");

    return 0;
}



