#include <bits/stdc++.h>
#define MAX 1005
#define ll long long

using namespace std;

ll T;
int n, m;
ll A[MAX], B[MAX];
vector<ll> pA, pB;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%lld", &T);

    scanf("%d", &n);
    for (int i=1;i<=n;i++){
        scanf("%lld", &A[i]);
    }
    scanf("%d", &m);
    for (int i=1;i<=m;i++){
        scanf("%lld", &B[i]);
    }

    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            if (i == j) pA.push_back(A[i]);
            else{
                ll temp = 0LL;
                for (int x=i;x<=j;x++){
                    temp += A[x];
                }
                pA.push_back(temp);
            }
        }
    }

    for (int i=1;i<=m;i++){
        for (int j=i;j<=m;j++){
            if (i==j) pB.push_back(B[i]);
            else{
                ll temp = 0LL;
                for (int x=i;x<=j;x++){
                    temp += B[x];
                }
                pB.push_back(temp);
            }
        }
    }

    sort(pA.begin(), pA.end());
    sort(pB.begin(), pB.end());

    ll cnt = 0LL;

    for (int a=0;a<pA.size();a++){
        ll b = T - pA[a];
        cnt += upper_bound(pB.begin(), pB.end(), b) - lower_bound(pB.begin(), pB.end(), b);
    }
    printf("%lld\n", cnt);




    return 0;
}
