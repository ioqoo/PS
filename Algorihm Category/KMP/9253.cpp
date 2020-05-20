#include <bits/stdc++.h>

const int MAX = 200005;

using namespace std;

string A, B, K;
int fail[MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> A >> B >> K;
    int M = K.size();
    
    for (int i=1,j=0;i<M;i++){
        while(j>0 && K[i] != K[j]) j = fail[j-1];
        if (K[i] == K[j]) fail[i] = ++j;
    }
    
    int N = A.size();
    bool succ = false;
    for (int i=0, j=0;i<N;i++){
        while(j>0 && A[i] != K[j]) j = fail[j-1];
        if (A[i] == K[j]) {
            if (j == M-1){
                succ = true;
                break;
            }
            else j++;
        }
    }
    if (!succ) {
        cout << "NO\n"; return 0;
    }
    succ = false;
    N = B.size();
    for (int i=0, j=0;i<N;i++){
        while(j>0 && B[i] != K[j]) j = fail[j-1];
        if (B[i] == K[j]) {
            if (j == M-1){
                succ = true;
                break;
            }
            else j++;
        }
    }
    if (!succ) {
        cout << "NO\n"; return 0;
    }
    cout << "YES\n";

    return 0;
}



