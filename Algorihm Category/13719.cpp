#include <bits/stdc++.h>

const int MAX = 1000005;
using namespace std;

int N;
int arr[MAX];
int pre[MAX], sur[MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        scanf("%d", &arr[i]);
    }
    
    for (int i=1;i<=N;i++){
        pre[i] = pre[i-1] + arr[i];
    }
    for (int i=N;i>=1;i--){
        sur[i] = sur[i+1] + arr[i];
    }
    int l = 1, r = N;
    int ans = 0;
    while(l<r){
        int left = pre[l], right = sur[r];
        if (left == right){
            l++; r--;
        }
        else if (left < right){
            l++;
            ans++;
        }
        else if (left > right){
            r--;
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}



