#include <bits/stdc++.h>

const int INF = 987654321;
using namespace std;

int N;
vector<int> arr;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d", &N);
    int currmin = INF;
    int curr;
    int ans = -1;
    for (int i=0;i<N;i++){
        scanf("%d", &curr);
        ans = max(ans, curr - currmin);
        currmin = min(currmin, curr);
    }
    printf("%d\n", ans);
    

    return 0;
}



