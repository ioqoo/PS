#include <bits/stdc++.h>
#define ll long long
#define MAX 1000000

using namespace std;

int N;
ll A[MAX];
ll B, C;
ll cnt;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);
    for (int i=0;i<N;i++){
        scanf("%lld", &A[i]);
    }
    scanf("%lld %lld", &B, &C);
    for (int i=0;i<N;i++){
        A[i] -= B;
        if (A[i] < 0LL) A[i] = 0LL;
        cnt++;
    }
    for (int i=0;i<N;i++){
        cnt += A[i] / C;
        if (A[i] % C) cnt++;
    }
    printf("%lld\n", cnt);
}
