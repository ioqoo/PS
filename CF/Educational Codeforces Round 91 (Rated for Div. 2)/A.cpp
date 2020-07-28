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
        int n;
        scanf("%d", &n);
        vector<int> arr;
        for (int i=0;i<n;i++){
            int temp;
            scanf("%d", &temp);
            arr.push_back(temp);
        }
        bool ascending = false;
        int last = -1;
        for (int i=1;i<n;i++){
            if (arr[i] > arr[i-1]) {
                ascending = true;
                last = i;
                break;
            }
        }
        if (!ascending) {
            printf("NO\n");
            continue;
        }
        bool descending = false;
        int last2 = -1;
        for (int i=last+1;i<n;i++){
            if (arr[i] < arr[i-1]){
                descending = true;
                last2 = i;
                break;
            }
        }
        if (!descending) {
            printf("NO\n");
            continue;
        }
        if (last2 == n){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        printf("%d %d %d\n", last2-1, last2, last2+1);
        
        
    }

    return 0;
}



