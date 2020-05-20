#include <bits/stdc++.h>

const int MAX = 200000;

using namespace std;

string S, K, H;
int fail[MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> S >> K;
    for (int i=0;i<S.size();i++){
        char c = S[i];
        int temp = c-'0';
        if (0 <= temp && temp <= 9) continue;
        H += c;
    }
    
    for (int i=1,j=0;i<K.size();i++){
        while(j>0 && K[i] != K[j]) j = fail[j-1];
        if (K[i] == K[j]) fail[i] = ++j;
    }
    
    for (int i=0,j=0;i<H.size();i++){
        while(j>0 && H[i] != K[j]) j = fail[j-1];
        if (H[i] == K[j]) {
            if (j==K.size() -1){
                cout << 1;
                return 0;
            }
            else j++;
        }
    }
    cout << 0;

    return 0;
}



