#include <bits/stdc++.h>
#define ll long long
#define MAX 1000005

using namespace std;

int T;
ll num[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &T);
    for (int x=0;x<T;x++){
        int N;
        scanf("%d", &N);
        for (int i=0;i<N;i++){
            scanf("%lld", &num[i]);
        }
        ll M = -1LL;
        ll ans = 0LL;
        for (int i=N-1;i>=0;i--){
            ll curr = num[i];
            if (curr > M) M = curr;
            else {
                ans += M - curr;
            }
        }
        printf("%lld\n", ans);
    }
}
