#include <iostream>
#include <queue>

#define ll long long
const int MAX = 100005;
using namespace std;

int T, N;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &T);
    while(T--){
        priority_queue<ll, vector<ll>, greater<ll>> PQ;
        scanf("%d", &N);
        ll temp;
        for (int i=0;i<N;i++){
            scanf("%d", &temp);
            PQ.push(temp);
        }
        ll ans = 0;
        while(true){
            ll x = PQ.top();
            PQ.pop();
            if (PQ.empty()) break;
            ll y = PQ.top();
            PQ.pop();
            ans += x+y;
            PQ.push(x+y);
        }
        printf("%lld\n", ans);
    }

    return 0;
}



