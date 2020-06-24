#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    scanf("%d", &t);
    // cin >> t;
    while(t--){
        int n, x;
        scanf("%d %d", &n, &x);
        int oddcnt = 0, evencnt = 0;
        int total = 0;
        for (int i=0;i<n;i++){
            int temp;
            scanf("%d", &temp);
            total += temp;
            if (temp%2) oddcnt++;
            else evencnt++;
        }
        if (x==n){
            if (total % 2) printf("Yes\n");
            else printf("No\n");
        }
        else{
            bool succ = false;
            for (int i=0;i<=oddcnt;i++){
                if (((x-i)*2 + i)%2) {
                    printf("Yes\n");
                    succ = true;
                    break;
                }
            }
            if (!succ) printf("No\n");
        }
        
    }

    return 0;
}



