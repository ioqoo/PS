#include <bits/stdc++.h>
#define MAX 105

using namespace std;

int T;
bool sieve[MAX]; // false : closed
int ans[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &T);
    for (int i=1;i<=100;i++){
        for (int j=1;i*j<=100;j++){
            if (sieve[i*j]) sieve[i*j] = false;
            else sieve[i*j] = true;
        }
    }
    ans[1] = 1;
    for (int i=2;i<=100;i++){
        ans[i] += ans[i-1] + sieve[i];
    }
    for (int x=0;x<T;x++){
        int N;
        scanf("%d", &N);
        printf("%d\n", ans[N]);
    }
}
