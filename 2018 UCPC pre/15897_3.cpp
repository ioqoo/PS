#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> L;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   L.push_back(0);
   for (int t=1;t<=10000;t++){
       ll ans = 0;
       for (int i=1;i<=t;i++){
           for (int j=1;j<=t;j+=i){
               ans++;
           }
       }
       L.push_back(ans);
   }
   int cnt = 0;
   ll n;
    for (int t=1;t<=10000;t++){
        n = t;
        ll answer=1;
        ll k=sqrtl(n-1);
        if(n==1){
            cout << "YES\n";
             continue;
        }
        for(ll i=2;i<=sqrtl(n-1);i++){
          answer+=i*((n-1)/(i-1)-(n-1)/i);
        }
        for(ll i=1;i<=(n-1)/k;i++){
          answer+=(n-1)/i+1;
        }
        if (L[t] == answer) continue;
        else {
//            cout << "NO\n";
//            cout << "N = " << n << 
            cnt++;
        }
        
    }
    cout << cnt;

    return 0;
}



