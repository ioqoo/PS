#include <bits/stdc++.h>
#define MAX 10005
#define ll long long

using namespace std;

ll fib[92];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ll n;
    scanf("%lld", &n);

    fib[0] = 0;
    fib[1] = 1;
    for (int i=2;i<=90;i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    printf("%lld\n", fib[n]);


    return 0;
}
