#include <bits/stdc++.h>

#define pii pair<int, int>
const int MIN = -1987654321;
using namespace std;

int N;
vector<pii> line;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        line.push_back({u, v});
    }
    
    sort(line.begin(), line.end());
    
    int ans = 0;
    int ls = MIN, le = MIN;
    for (auto p: line){
        int a = p.first, b = p.second;
        if (le < a){
            ans += le-ls;
            ls = a; le = b;
        }
        else{
            le = max(le, b);
        }
    }
    ans += le-ls;
    printf("%d\n", ans);

    return 0;
}



