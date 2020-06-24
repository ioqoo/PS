#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

int N, L, a;
deque<pii> dq;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        scanf("%d", &a);
        while(dq.size() && dq.front().first <= i - N) {
            dq.pop_front();
        }
        
        while(dq.size() && dq.back().second <= a) {
            dq.pop_back();
        }
        dq.push_back(pii(i, a));
        
        printf("%d ", dq.front().second);
    }

    return 0;
}
