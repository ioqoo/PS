#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        int temp;
        scanf("%d", &temp);
        arr.push_back(temp);
    }
    
    sort(arr.begin(), arr.end(), greater<int>());
    int ans = max(max(arr[0]*arr[1], arr[0]*arr[1]*arr[2]), max(arr[N-2]*arr[N-1], arr[0]*arr[N-2]*arr[N-1]));
    printf("%d\n", ans);

    return 0;
}



