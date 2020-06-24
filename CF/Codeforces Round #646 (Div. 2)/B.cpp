#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
//    scanf("%d", &t);
    cin >> t;
    while(t--){
        string row;
        cin >> row;
        if (row.size() <= 2){
            cout << 0 << "\n";
            continue;
        }
        int N = row.size();
        int ans = 100000000;
        for (int i=0;i<N;i++){
            int leftzero = 0, rightzero = 0;
            int leftone = 0, rightone = 0;
            for (int j=0;j<i;j++){
                if (row[j] == '0') leftzero++;
                else leftone++;
            }
            for (int j=i+1;j<N;j++){
                if (row[j] == '0') rightzero++;
                else rightone++;
            }
//            cout << leftzero << " " << leftone << endl;
//            cout << rightzero << " " << rightone << endl;
            ans = min(ans, min(leftzero + rightone, leftone + rightzero));
        }
        cout << ans << endl;
    }

    return 0;
}



