#include <bits/stdc++.h>
#define MAX 1000000005
#define ll long long

using namespace std;

ll X, Y, Z;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%lld %lld", &X, &Y);
    ll Z = Y * 100LL / X;

    int l = 0, r = MAX;
    int mid = (l+r) / 2;
    bool succ = false;

    while(l+1 < r){
        ll curr = (Y + mid) * 100LL / (X + mid);
//        printf("%d %d %d\n", l, r, curr);
        if (curr > Z) {
            r = mid;
            succ = true;
        }
        else{
            l = mid;
        }
        mid = (l + r) / 2;
    }

    printf("%d\n", succ ? mid + 1 : -1);

    return 0;
}
