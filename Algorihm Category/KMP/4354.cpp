#include <bits/stdc++.h>

const int MAX = 1000005;
using namespace std;

int fail[MAX];
string row;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    while(1){
        cin >> row;
        memset(fail, 0, sizeof(fail));
        if (row == ".") break;
        
        int M = row.size();
        
        for (int i=1,j=0;i<M;i++){
            while(j>0 && row[i] != row[j]) j = fail[j-1];
            if (row[i] == row[j]) fail[i] = ++j;
        }
        
        int F = fail[M-1];
        int ans = 1;
        if (!(M%2 && F%(M-F))) {
            ans = M / (M-F);
        }
        cout << ans << endl;
        
        
    }    
    

    return 0;
}



