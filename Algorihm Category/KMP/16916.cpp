#include <bits/stdc++.h>

const int MAX = 1000005;

using namespace std;

string S, P;
int fail[MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> S >> P;
    int N = S.size();
    int M = P.size();
    for (int i=1,j=0;i<M;i++){
        while(j>0 && P[i] != P[j]) j = fail[j-1];
        if (P[i] == P[j]) fail[i] = ++j;
    }
    
    for (int i=0,j=0;i<N;i++){
        while(j>0 && S[i] != P[j]) j = fail[j-1];
        if (S[i] == P[j]){
            if (j == M-1){
                cout << "1\n";
                return 0;
            }
            else j++;
        }
    }
    cout << "0\n";

    return 0;
}



