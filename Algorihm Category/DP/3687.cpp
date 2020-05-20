#include <bits/stdc++.h>


using namespace std;

bool dp[130][55];
int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string ans;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    for (int i=2;i<=7;i++){
        dp[i][1] = true;
    }
    for (int j=2;j<=55;j++){
        for (int i=2;i<=100;i++){
            if (dp[i][j-1] == true){
                for (int k=2;k<=7;k++){
                    dp[i+k][j] = true;
                }
            }
        }
    }
    
    int t;
    cin >> t;
    while(t--){
        int n;
        ans = "";
        cin >> n;
        
        bool first = true;
        int digit = 1, remain = n;
        while(remain > 0) {
            if (dp[remain][digit]){ // can make
                if (digit == 1){
                    for (int i=0;i<=9;i++){
                        if (first && i==0) continue;
                        if (dp[num[i]][1] && num[i] == remain) {
                            ans = ans + (char)(i+'0');
                            break;
                        }
                    }
                    break;
                }
                for (int k=0;k<=9;k++){
                    if (dp[remain-num[k]][digit-1]){
                        if (first && k == 0) continue;
                        ans = ans + (char)(k + '0');
                        first = false;
                        remain -= num[k];
                        digit--;
                        break;
                    }
                }
            }
            else digit++;
        }
        cout << ans << " ";
        
        if (n%2 == 0) {
            for (int i=0;i<n/2;i++){
                cout << "1";
            }
            cout << endl;
        }
        else{
            cout << "7";
            for (int i=0;i<(n-3)/2;i++){
                cout << "1";
            }
            cout << endl;
        }
        
    }
    

    return 0;
}



