#include <bits/stdc++.h>

const int INF = 987654321;
const int MAX = 53;
using namespace std;

int N;
vector<int> arr;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    scanf("%d", &t);
    while(t--){
        
        scanf("%d", &N);
        arr.clear();
        for (int i=0;i<N;i++){
            int temp;
            scanf("%d", &temp);
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end());
        int ans = INF;
        for (int i=0;i<N-1;i++){
            ans = min(ans, arr[i+1] - arr[i]);
        }
        printf("%d\n", ans);
        
        
    }
    
    return 0;
}



