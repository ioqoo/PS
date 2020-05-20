#include <bits/stdc++.h>

const int MAX = 1000005;

using namespace std;

int L;
int fail[MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> L;
    string K;
    cin >> K;
    int M = K.size();
    for (int i=1, j=0;i<M;i++){
        while(j>0 && K[i] != K[j]) j = fail[j-1];
        if (K[i] == K[j]) fail[i] = ++j;
    }
    
    cout << M - fail[M-1];

    return 0;
}



