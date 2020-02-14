#include <bits/stdc++.h>
#define MAX 10005
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

struct compare{
    bool operator()(pii A, pii B){
        if (A.second != B.second) return A.second < B.second;
        else return A.first < B.first;
    }
};



int N, K;
multiset<int> bag;
priority_queue<pii, vector<pii>, compare> PQ;
ll ans;


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);

    scanf("%d %d", &N, &K);
    for (int i=0;i<N;i++){
        int m, v;
        scanf("%d %d", &m, &v);
        PQ.push(pii(m, v));
    }
    for (int i=0;i<K;i++){
        int c;
        scanf("%d", &c);
        bag.insert(c);
    }

    while(!PQ.empty()){
        auto p = PQ.top();
//        printf("%d %d\n", p.first, p.second);
        PQ.pop();
        if (bag.lower_bound(p.first) != bag.end()){
            ans += p.second;
            bag.erase(bag.lower_bound(p.first));
        }
    }

    printf("%lld\n", ans);



    return 0;
}
