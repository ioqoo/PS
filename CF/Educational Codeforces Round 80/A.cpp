#include <bits/stdc++.h>
#define MAX 505

using namespace std;

int T;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%d", &T);
    for (int i=0;i<T;i++){
        int n, d;
        scanf("%d %d", &n, &d);
        if (n >= d) printf("YES\n");
        else{
            if (n/2 + (int)(ceil(d/(n/2 + 1.0))) <= n) printf("YES\n");
            else printf("NO\n");
        }
    }
}
