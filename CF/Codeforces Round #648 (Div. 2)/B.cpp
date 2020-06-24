#include <bits/stdc++.h>

#define ll long long
const int MAX = 505;
using namespace std;

int N;
int a[MAX];
int b[MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    scanf("%d", &t);
    // cin >> t;
    while(t--){
        scanf("%d", &N);
        int onecnt = 0, zerocnt = 0;
        for (int i=0;i<N;i++){
            scanf("%d", &a[i]);
        }
        for (int i=0;i<N;i++){
            scanf("%d", &b[i]);
            if (b[i] == 0) zerocnt++;
            else onecnt++;
        }
        if (zerocnt == N || onecnt == N){
            bool succ = true;
            for (int i=0;i<N-1;i++){
                if (a[i] > a[i+1]){
                    succ = false;
                    break;
                }
            }
            if (succ) {
                printf("Yes\n");
            }
            else printf("No\n");
        }
        else printf("Yes\n");
    }

    return 0;
}



