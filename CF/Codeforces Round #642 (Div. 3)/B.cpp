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
        int n, k;
        scanf("%d %d", &n, &k);
        vector<int> a, b;
        int temp;
        for (int i=0;i<n;i++){
            scanf("%d", &temp);
            a.push_back(temp);
        }
        for (int i=0;i<n;i++){
            scanf("%d", &temp);
            b.push_back(temp);
        }
        sort(b.begin(), b.end());
        for (int i=n-1;i>n-k-1;i--){
            a.push_back(b[i]);
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i=k;i<n+k;i++){
            ans += a[i];
        }
        printf("%d\n", ans);
        
    }

    return 0;
}



