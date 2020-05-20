#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int sum[44];


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    
    scanf("%d %d", &N, &M);
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            sum[i+j]++;
        }
    }
    
    int max_val = *max_element(sum+1, sum+N+M+1);
    for (int i=1;i<=N+M;i++){
        if (sum[i] == max_val){
            printf("%d\n", i);
        }
    }
    
    

    return 0;
}



