#include <bits/stdc++.h>

const int INF = 2e9;
const int MAX = 100005;
using namespace std;

int N;
int arr[MAX];
bool l[MAX], r[MAX];


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        scanf("%d", &arr[i]);
    }
    
    arr[0] = -INF;
    l[0] = true;
    for (int i=1;i<=N;i++){
        if (!l[i-1]) break;
        if (arr[i-1] <= arr[i]) l[i] = true;
    }
    arr[N+1] = INF;
    r[N+1] = true;
    for (int i=N;i>=1;i--){
        if (!r[i+1]) break;
        if (arr[i] <= arr[i+1]) r[i] = true;
    }
    
    int ans = 0;
    for (int i=1;i<=N;i++){
        if (!l[i-1] || !r[i+1]) continue;
        if (arr[i-1] <= arr[i+1]) ans++;
    }
    printf("%d\n", ans);
    

    return 0;
}



