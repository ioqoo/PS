#include <bits/stdc++.h>
#define MAX 10005
#define ll long long

using namespace std;

int K, N;
vector<ll> primes;
priority_queue<ll, vector<ll>, greater<ll>> PQ;
map<ll, bool> mp;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);

    scanf("%d %d", &K, &N);
    for (int i=0;i<K;i++){
        ll n;
        scanf("%lld", &n);
        primes.push_back(n);
        PQ.push(n);
    }

    ll prev_pop = 0LL;
    ll curr_pop;
    int cnt = 0;

    while(true){
        ll curr = PQ.top();
        PQ.pop();
        if (curr == prev_pop){
            continue;
        }
        else{
            for (auto n: primes){
                if (curr * n >= INT_MAX){
                    break;
                }
                if (mp[curr*n]) continue;
                PQ.push(curr * n);
                mp[curr*n] = true;
            }
            cnt++;
            curr_pop = curr;
        }
        if (cnt == N){
            break;
        }
        else{
            prev_pop = curr;
        }
    }

    printf("%lld\n", curr_pop);

//    printf("%lld\n", PQ.top());






    return 0;
}
