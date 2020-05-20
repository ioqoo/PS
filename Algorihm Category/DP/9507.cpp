#include <bits/stdc++.h>
#define MAX 68
#define ll long long

using namespace std;

ll fib[MAX];
int t;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    fib[0] = fib[1] = 1LL;
    fib[2] = 2LL;
    fib[3] = 4LL;
    for (int i=4;i<=67;i++){
        fib[i] = fib[i-1] + fib[i-2] + fib[i-3] + fib[i-4];
    }
    scanf("%d", &t);
    for (int x=0;x<t;x++){
        int n;
        scanf("%d", &n);
        printf("%lld\n", fib[n]);
    }
}
