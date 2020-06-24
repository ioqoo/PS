#include <bits/stdc++.h>

#define ll long long
using namespace std;

struct rect{
    ll x, y;
    bool operator < (const rect &B){
        if (x == B.x) return y < B.y;
        return x > B.x;
    }
    ll area(){
        return x*y;
    }
};

int N;
vector<rect> arr;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        ll x, y;
        scanf("%lld %lld", &x, &y);
        arr.push_back({x, y});
    }  
    sort(arr.begin(), arr.end());
    
    ll ans = 0;
    rect prev;
    for (int i=0;i<N;i++){
//        printf("%lld %lld\n", arr[i].x, arr[i].y);
        if (i==0){
            ans += arr[0].area();
            prev = arr[0];
        }
        else{
            ans += arr[i].area();
            ans -= min(prev.x, arr[i].x) * min(prev.y, arr[i].y);
            if (prev.y < arr[i].y) prev = arr[i];
        }
    }
    printf("%lld\n", ans);
    
    

    return 0;
}



