// https://www.acmicpc.net/problem/18230

#include <bits/stdc++.h>

using namespace std;

int N, A, B;
int one[2005];
int two[2005];
int ans;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d %d", &N, &A, &B);
    for (int i=0;i<A;++i){
        scanf("%d", &one[i]);
    }
    for (int i=0;i<B;i++){
        scanf("%d", &two[i]);
    }
    sort(one, one+A, greater<int>());
    sort(two, two+B, greater<int>());

    if (N==1) {
        printf("%d\n", one[0]);
        return 0;
    }
    int o = 0, t = 0, n = N;
    if (n%2) {
        ans += one[o];
        o += 1;
        n -= 1;
    }
    while (n > 0){
        if (o >= A-1){
            ans += two[t];
            t += 1;
            n -= 2;
            continue;
        }
        else if (t == B){
            ans += one[o] + one[o+1];
            o += 2;
            n -= 2;
            continue;
        }
        if (two[t] > one[o] + one[o+1]){
            ans += two[t];
            t += 1;
            n -= 2;
        }
        else {
            ans += one[o] + one[o+1];
            o += 2;
            n -= 2;
        }
    }
    printf("%d\n", ans);
}
