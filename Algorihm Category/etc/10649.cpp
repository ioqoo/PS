#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
using namespace std;


struct cow{
    int num, height, weight, power;
    bool operator < (cow b){
        return weight + power > b.weight + b.power;
    }
};

int N, H;
vector<cow> C;
int ans = -1;

void solve(int total_h, int total_w, int curr, vector<int> &list){
    
    if (total_h >= H){
        int ret = INF;
        int curr_w = total_w;
        for (int i=0;i<list.size()-1;i++){
            int curr_p = C[list[i]].power;
            if (curr_w > curr_p){
                return;
            }
            ret = min(ret, curr_p - curr_w);
            curr_w -= C[list[i+1]].weight;
        }
        ret = min(ret, C[list.back()].power);
        if (ret != INF) ans = max(ret, ans);
        return;
    }
    
    for (int i=curr+1;i<N;i++){
        list.push_back(i);
        solve(total_h + C[i].height, total_w + C[i].weight, i, list);
        list.pop_back();
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d %d", &N, &H);
    for (int i=1;i<=N;i++){
        int h, w, p;
        scanf("%d %d %d", &h, &w, &p);
        C.push_back({i, h, w, p});
    }
    sort(C.begin(), C.end());
    
    vector<int> L;
    for (int i=0;i<N;i++){
        L.push_back(i);
        solve(C[i].height, 0, i, L);
        L.pop_back();
    }
    if (ans == -1) printf("Mark is too tall\n");
    else printf("%d\n", ans);
    
    

    return 0;
}



