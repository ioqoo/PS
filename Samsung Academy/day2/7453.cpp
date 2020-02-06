#include <bits/stdc++.h>
#define MAX 4005
#define ll long long

using namespace std;

int n;
ll A[MAX], B[MAX], C[MAX], D[MAX];
vector<ll> CD;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    for (int i=0;i<n;i++){
        scanf("%lld %lld %lld %lld", &A[i], &B[i], &C[i], &D[i]);
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            CD.push_back(C[i] + D[j]);
        }
    }

    sort(CD.begin(), CD.end());

    ll cnt = 0LL;

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            ll cd = -(A[i] + B[j]);
            cnt += upper_bound(CD.begin(), CD.end(), cd) - lower_bound(CD.begin(), CD.end(), cd);
        }
    }

//    int ab = 0, cd = 0;
//    ll sum = -1LL;
//
//    while(1){
//        if (sum >= 0){
//            sum -= CD[cd++];
//        }
//        else if ()
//    }

    printf("%lld\n", cnt);

    return 0;
}
