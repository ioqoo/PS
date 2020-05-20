#include <bits/stdc++.h>

const int MAX = 5000;

using namespace std;

string K;
int fail[MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     
    cin >> K;
    int N = K.size();
    int ans = 0;
    for (int k=0;k<N;k++){
        string S = K.substr(k, N-k);
        memset(fail, 0, sizeof(fail));
        for (int i=1, j=0;i<S.length();i++){
            while(j>0 && S[i] != S[j]) j = fail[j-1];
            if (S[i] == S[j]) fail[i] = ++j;
        }
        ans = max(ans, *max_element(fail, fail+N));
    }
    printf("%d\n", ans);

    return 0;
}



