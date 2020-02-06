#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int N, S;
int arr[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &N, &S);

    for (int i=0;i<N;i++){
        scanf("%d", &arr[i]);
    }

    int l = 0, r = 0, sum = 0;
    int ans = MAX;
    while(1){
        if (sum >= S){
            sum -= arr[l++];
        }
        else if (r == N) break;
        else {
            sum += arr[r++];
        }
        if (sum >= S){
            ans = min(ans, r-l);
        }
    }
    printf("%d\n", ans==MAX ? 0 : ans);


    return 0;
}
