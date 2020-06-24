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
        set<int> S;
        int N;
        scanf("%d", &N);
        for (int i=0;i<N;i++){
            int temp;
            scanf("%d", &temp);
            S.insert(temp);
        }
        int ans = 0;
        bool succ = false;
        while(ans < 1024){
            set<int> comp;
            ans++;
            for (auto it=S.begin();it!=S.end();it++){
                int curr = *it;
                comp.insert(curr ^ ans);
            }
            if (S == comp){
                printf("%d\n", ans);
                succ = true;
                break;
            }
        }
        if (!succ){
            printf("-1\n");
        }
        
    }

    return 0;
}



