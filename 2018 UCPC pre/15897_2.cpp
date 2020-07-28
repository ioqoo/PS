#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 

ll n;
vector<ll> L;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
   
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   
   cin>>n;
   if (n < 10){
       ll ans = 0;
       for (int i=1;i<=n;i++){
           for (int j=1;j<=n;j+=i){
               ans++;
           }
       }
       cout << ans;
       return 0;
   }
   ll answer=1;
   for(ll i=2;i<=sqrtl(n-1);i++){
      answer+=i*((n-1)/(i-1)-(n-1)/i);
   }
   for(ll i=1;i<=(n-1)/(sqrtl(n-1));i++){
      answer+=(n-1)/i+1;
   }
   cout<<answer;
   
   return 0;
}
