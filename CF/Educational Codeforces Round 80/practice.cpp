#include <bits/stdc++.h>
#define ll long long
#define MAX 505

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int t;
    scanf("%d", &t);
    for (int i=0;i<t;i++){
        ll a, b;
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", a * (ll)floor(log10(b)));
    }
}
