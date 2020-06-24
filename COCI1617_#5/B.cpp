#include <bits/stdc++.h>

#define ll long long
const int MAX = 300005;
using namespace std;

int N;
ll psum[MAX];
vector<ll> arr;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d", &N);
    ll total = 0LL;
    for (int i=0;i<N;i++){
        ll temp;
        scanf("%lld", &temp);
        total += temp;
        arr.push_back(temp);
//        if (i==0) psum[i] = temp;
//        else psum[i] = psum[i-1] + temp;
    }
    sort(arr.begin(), arr.end(), greater<ll>());
    
    for (int i=0;i<N;i++){
        if (i==0) psum[i] = arr[0];
        else psum[i] = psum[i-1] + arr[i];
    }
    
    double ans = 0;
    double ansA, ansB;
    for (int i=0;i<N;i++){
        int high = i+1;
        double A = (double)high / (double)N * 100.;
        ll have = psum[i];
        double B = (double)have / (double)total * 100.;
//        printf("%lf %lf\n", A, B);
        if (ans < B-A){
            ans = B-A;
            ansA = A, ansB = B;
        }
    }
    printf("%lf\n%lf", ansA, ansB);
    

    return 0;
}



