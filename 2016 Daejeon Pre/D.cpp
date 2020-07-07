#include <bits/stdc++.h>
#define ll long long
const ll MOD = 31991LL;

using namespace std;

ll d, t;
vector<vector<ll>> A;
vector<vector<ll>> Apow;
map<ll, vector<vector<ll>>> mp;
vector<ll> init;

vector<vector<ll>> matmul(vector<vector<ll>> A, vector<vector<ll>> B){
    vector<vector<ll>> ret;
    for (int i=0;i<d;i++){
        ret.push_back(vector<ll>(d));
    }
    
    for (int i=0;i<d;i++){
        for (int j=0;j<d;j++){
            for (int k=0;k<d;k++){
                ret[i][j] = (ret[i][j] + (A[i][k] * B[k][j])%MOD)%MOD;
            }
        }
    }
    
    return ret;
}

vector<vector<ll>> solve(int pow){ // returns A^pow
    if (pow == 1){
        return A;
    }
    else if (pow == 2){
        return Apow;
    }
    else{
        if (mp.count(pow)) return mp[pow];
        if (pow%2){ // odd
            return mp[pow] = matmul(solve(pow/2), solve(pow/2 + 1));
        }
        else{ // even
            return mp[pow] = matmul(solve(pow/2), solve(pow/2));
        }
    }
}

ll getans(vector<vector<ll>> A, vector<ll> B){
    ll ret = 0;
    for (int i=0;i<d;i++){
        ret = (ret + (A[d-1][i] * B[i])%MOD)%MOD;
    }
    
    return ret;
}




int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%lld %lld", &d, &t);
    for (int i=0;i<d;i++){
        A.push_back(vector<ll>(d));
        Apow.push_back(vector<ll>(d));
    }

    for (int i=0;i<d;i++){
        A[d-1][i] = 1;
    }
    for (int i=0;i<d-1;i++){
        A[i][i+1] = 1;
    }

    Apow = matmul(A, A);
    
    
//    for (int i=0;i<d;i++){
//        for (int j=0;j<d;j++){
//            printf("%d ", A[i][j]);
//        }
//        printf("\n");
//    }
//    
//    printf("\n");
//
//    
//    for (int i=0;i<d;i++){
//        for (int j=0;j<d;j++){
//            printf("%d ", Apow[i][j]);
//        }
//        printf("\n");
//    }    

//    vector<vector<int>> C = matmul(A, A);
//    for (int i=0;i<d;i++){
//        for (int j=0;j<d;j++){
//            printf("%d ", C[i][j]);
//        }
//        printf("\n");
//    }        

    init.push_back(1);
    for (int i=0;i<d-1;i++){
        init.push_back((1LL<<i)%MOD);
    }
    
    if (t < d){
        printf("%lld\n", init[t]%MOD);
        return 0;
    }
    
    
    vector<vector<ll>> powered = solve(t-d+1);
    printf("%lld\n", getans(powered, init));
//    for (int i=0;i<d;i++){
//        for (int j=0;j<d;j++){
//            printf("%d ", powered[i][j]);
//        }
//        printf("\n");
//    }            

    return 0;
}



