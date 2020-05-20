#include <bits/stdc++.h>

const int MAX = 1000005;

using namespace std;

int N;
string H, K;
int fail[MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    string c;
    for (int i=0;i<N;i++){
        cin >> c;
        K += c;
    }
    for (int i=0;i<N;i++){
        cin >> c;
        H += c;
    }
    H += H;
    
    for (int i=1,j=0;i<N;i++){
        while(j>0 && K[i] != K[j]) j = fail[j-1];
        if (K[i] == K[j]) fail[i] = ++j;
    }
    
    vector<int> pos;
    for (int i=0,j=0;i<2*N;i++){
        while(j>0 && H[i] != K[j]) j = fail[j-1];
        if (H[i] == K[j]){
            if (j == N-1){
                if (i-(N-1) != N) pos.push_back(i-(N-1));
                j = fail[j];
            }
            else j++;
        }
    }
    int a = pos.size();
    int b = N;
    int gcd = __gcd(a, b);
    cout << a/gcd << "/" << b/gcd;

    return 0;
}



