#include <bits/stdc++.h>

using namespace std;



int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    scanf("%d", &t);
    while(t--){
        int N;
        vector<int> arr;
        scanf("%d", &N);
        for (int i=0;i<N;i++){
            int temp;
            scanf("%d", &temp);
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i=N-1;i>=0;i--){
            if (i+1 >= arr[i]){
                ans = i+1;
                break;
            }
        }
        printf("%d\n", ans+1);
        
    }

    return 0;
}



