// https://www.acmicpc.net/problem/18234
// 문제 조건 잘 이해해서 greedy하게

#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll N, T;
pll arr[200000];
ll ans;

bool cmp(const pll &a, const pll &b){
    return a.second < b.second;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%lld %lld", &N, &T);
    for (int i=0;i<N;i++){
        ll w, p;
        scanf("%lld %lld", &w, &p);
        arr[i] = pll(w, p);
    }
    sort(arr, arr+N, cmp);
    for (int i=0;i<N;i++){
        ans += arr[i].second * (i + T-N) + arr[i].first;
    }
    printf("%lld\n", ans);
}
