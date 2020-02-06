#include <bits/stdc++.h>
#define ll long long
#define MAX 1030

using namespace std;

ll nums[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ll N;
    scanf("%lld", &N);
    memset(nums, -1, sizeof(nums));
    nums[0] = 0LL;

    for (ll i=1LL;i<=9LL;i++){
        nums[i] = i;
    }

    queue<ll> q;
    for (ll i=1LL;i<=9LL;i++){
        q.push(i);
    }
    int cnt = 9;


    while(cnt < N){
        ll curr = q.front();
        q.pop();
        ll last = curr % 10LL;
        for (ll i = 0LL;i<last;i++){
            q.push(curr * 10LL + i);
            cnt++;
            nums[cnt] = curr * 10LL + i;
//            printf("%lld\n", nums[cnt]);
            if (nums[cnt] == 9876543210LL) {
                cnt = N;
                break;
            }
        }
    }

    printf("%lld", N >= MAX ? -1LL : nums[N]);
}
