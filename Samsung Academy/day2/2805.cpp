#include <bits/stdc++.h>
#define INF 2000000100
#define MAX 1000005
#define ll long long

using namespace std;

ll N, M;
ll tree[MAX];


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &N, &M);
    for (int i=0;i<N;i++){
        scanf("%d", &tree[i]);
    }

    ll l = 0LL, r = INF;
    ll mid = (l + r) / 2LL;
    while(l +1 < r){
        ll curr_sum = 0LL;
        for (int i=0;i<N;i++){
            curr_sum += max(0LL, tree[i] - mid);
        }

        if (curr_sum < M){
            r = mid;
        }
        else{
            l = mid;
        }
        mid = (l + r) / 2LL;
    }
    printf("%lld\n", mid);


    return 0;

}
