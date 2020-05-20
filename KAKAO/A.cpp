#include <bits/stdc++.h>

#define pii pair<int, int>
using namespace std;

int N;
vector<int> price;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        int temp;
        scanf("%d", &temp);
        price.push_back(temp);
    }
    
    vector<pii> a;
    for (int i=0;i<N;i++){
        a.push_back(pii(price[i], i));
    }
    sort(a.begin(), a.end(), greater<pii>());
    int last = -1;
    int ans = 0;
    for (auto p: a){
        int pos = p.second;
//        printf("%d %d\n", pos+1, last+1);
        if (pos < last) continue;
        for (int i=last+1;i<=pos;i++){
            ans += p.first - price[i];
        }
        last = pos;
    }
    printf("%d\n", ans);
    

    return 0;
}



