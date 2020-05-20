#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string bit;
        cin >> bit;
        int first = -1;
        int last = -1;
        for (int i=0;i<n;i++){
            if (bit[i] == '1') {
                first = i;
                break;
            }
        }
        for (int i=n-1;i>=0;i--){
            if (bit[i] == '1'){
                last = i;
                break;
            }
        }
        if (first == last) {
            cout << 0 << endl;
            continue;
        }
        bit = bit.substr(first, last+1);
        cout << bit << endl;
        int cnt = 0;
        for (int i=0;i<bit.size();i++){
            char curr = bit[i];
            if (i%k != 0){
                if (curr == '1'){
                    cnt++;
                }
            }
            else{
                if (curr == '0'){
                    cnt++;
                }
            }
        }
        int cnt2 = 0;
        
        cout << cnt << "\n";
    }
    
    return 0;
}



