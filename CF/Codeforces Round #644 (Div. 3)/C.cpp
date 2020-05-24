#include <bits/stdc++.h>

#define pii pair<int, int>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    scanf("%d", &t);
    vector<int> arr;
    int N;
    while(t--){
        arr.clear();
        vector<int> even;
        vector<int> odd;
        scanf("%d", &N);
        for (int i=0;i<N;i++){
            int temp;
            scanf("%d", &temp);
            if (temp%2) even.push_back(temp);
            else odd.push_back(temp);
            arr.push_back(temp);
        }
        if (even.size() == odd.size()){
            if (even.size() % 2 == 1){
                printf("NO\n");
            }
            else{
                printf("YES\n");
            }
            continue;
        }
        
        
        
        
        
        
    }

    return 0;
}



