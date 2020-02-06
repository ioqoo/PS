#include <bits/stdc++.h>
#define MOD 1000000LL
#define ll long long

using namespace std;

ll n;

vector<ll> matmul(ll A11, ll A12, ll A21, ll A22, ll B11, ll B12, ll B21, ll B22){
    ll C11 = ((A11*B11)%MOD + (A12*B21)%MOD)%MOD;
    ll C12 = ((A11*B12)%MOD + (A12*B22)%MOD)%MOD;
    ll C21 = ((A21*B11)%MOD + (A22*B21)%MOD)%MOD;
    ll C22 = ((A21*B12)%MOD + (A22*B22)%MOD)%MOD;
    vector<ll> ret;
    ret.push_back(C11);
    ret.push_back(C12);
    ret.push_back(C21);
    ret.push_back(C22);
    return ret;
}

vector<ll> dc(ll n){
    if (n == 1){
        ll temp[] = {1LL, 1LL, 1LL, 0LL};
        vector<ll> ret;
        for (int i=0;i<4;i++){
            ret.push_back(temp[i]);
        }
        return ret;
    }
    else if (n == 2){
        ll temp[] = {2LL, 1LL, 1LL, 1LL};
        vector<ll> ret;
        for (int i=0;i<4;i++){
            ret.push_back(temp[i]);
        }
        return ret;
    }
    else{
        if (n%2) {
            vector<ll> temp = dc(n/2);
            ll a = temp[0];
            ll b = temp[1];
            ll c = temp[2];
            ll d = temp[3];
            vector<ll> temp2 = matmul(a, b, c, d, a, b, c, d);
            return matmul(temp2[0], temp2[1], temp2[2], temp2[3], 1LL, 1LL, 1LL, 0LL);
        }
        else{
            vector<ll> temp = dc(n/2);
            ll a = temp[0];
            ll b = temp[1];
            ll c = temp[2];
            ll d = temp[3];
            return matmul(a, b, c, d, a, b, c, d);
        }
    }

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%lld", &n);
    if (n == 1LL){
        printf("1");
        return 0;
    }

    vector<ll> ans = dc(n-1);

    printf("%lld\n", ans[0]);

    return 0;
}
