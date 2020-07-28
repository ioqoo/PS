#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    unordered_set<string> S;
    string word;
    for (int i=0;i<N;i++){
        cin >> word;
        S.insert(word);
    }
    int ans = 0;
    for (int i=0;i<M;i++){
        cin >> word;
        if (S.count(word)) ans++;
    }
    cout << ans;

    return 0;
}



