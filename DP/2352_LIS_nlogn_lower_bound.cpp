#include <bits/stdc++.h>
#define MAX 40005
#define INF 987654321

using namespace std;

int N;
int nums[MAX];
int d[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);

    for (int i=1;i<=N;i++){
        scanf("%d", &nums[i]);
    }

    d[1] = nums[1];
    int len = 1;

    for (int i=2;i<=N;i++){
        int curr = nums[i];
        if (d[len] < curr) {
            d[++len] = nums[i];
            continue;
        }
        int ind = lower_bound(d+1, d+len+1, curr) - d;
        d[ind] = nums[i];
    }
    printf("%d\n", len);
}
