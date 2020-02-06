#include <bits/stdc++.h>
#define MAX 15

using namespace std;

int col[MAX];
int ans;
int N;

bool promising(int i){
    for (int j=0;j<i;j++){
        if (col[i] == col[j] || abs(col[i] - col[j]) == abs(i-j)){
            return false;
        }
    }
    return true;
}

void bt(int i){
    if (i == N) {
        ans++;
        return;
    }
    for (int j=0;j<N;j++){
        col[i] = j;
        if (promising(i)){
            bt(i+1);
        }

    }



}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);

    bt(0);

    printf("%d\n", ans);
    return 0;

}
