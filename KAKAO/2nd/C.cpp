#include <bits/stdc++.h>

using namespace std;

int bit[1005];

int getans(string S){
    memset(bit, 0, sizeof(bit));
    bit[0] |= 1 << (S[0]-'a');
    for (int i=1;i<S.size();i++){
        bit[i] = bit[i-1] ^ (1 << (S[i]-'a')); // toggle
    }
    int ret = 0;
    for (int i=0;i<S.size();i++){
        for (int j=i;j<S.size();j++){
            int substring = bit[i-1] ^ bit[j];
            if ((substring & (substring-1)) == 0) ret++;
        }
    }
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    printf("%d\n", getans("bbrrg"));

    return 0;
}



