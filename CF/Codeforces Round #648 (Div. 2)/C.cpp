#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> a, b;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        int temp;
        scanf("%d", &temp);
        a.push_back(temp);
    }
    for (int i=0;i<N;i++){
        a.push_back(a[i]);
    }    
    for (int i=0;i<N;i++){
        int temp;
        scanf("%d", &temp);
        b.push_back(temp);
    }
    for (int i=0;i<N;i++){
        b.push_back(b[i]);
    }        
    int x = 0, y = 0;
    int ans = 0;
    int curr = 0;
    while(y < 2*N){
        printf("%d %d\n", a[x], b[y]);
        if (a[x] == b[y]){
            x = ((x+1)%N); y++;
            curr++;
            if (curr == N){
                printf("%d\n", N);
                return 0;
            }
        }
        else{
            ans = max(ans, curr);
            curr = 0;
            x++;
        }
    }
    printf("%d\n", ans);

    return 0;
}



