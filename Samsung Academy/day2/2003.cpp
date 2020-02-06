#include <bits/stdc++.h>
#define MAX 10005

using namespace std;

int N, M;
int arr[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &N, &M);
    for (int i=1;i<=N;i++){
        scanf("%d", &arr[i]);
    }

    int l = 1, r = 1;
    int curr_sum = 0;
    int cnt = 0;

    while(true){

        if (curr_sum >= M){
            curr_sum -= arr[l++];
        }
        else if (r == N+1) break;
        else {
            curr_sum += arr[r++];
        }
        if (curr_sum == M){
            cnt++;
        }
    }

    printf("%d\n", cnt);

    return 0;

}
