#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N, W, L;
    scanf("%d %d %d", &N, &W, &L);
    vector<int> truck;
    for (int i=0;i<N;i++){
        int temp;
        scanf("%d", &temp);
        truck.push_back(temp);
    }
    
    int t = 0;
    int pos = 0;
    int on_bridge_weight = 0;
    queue<pii> Q;
    while(pos < N){
        t++;
        if (!Q.empty() && Q.front().second + W == t){
            on_bridge_weight -= Q.front().first;
            Q.pop();
        }
        int curr_truck = truck[pos];
        if (on_bridge_weight + curr_truck <= L){
            on_bridge_weight += curr_truck;
            Q.push({curr_truck, t});
            pos++;
        }
    }
    printf("%d\n", t+W);
    

    return 0;
}



