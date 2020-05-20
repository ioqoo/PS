#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> vt;
int cnt = 0;

struct seg{
    int l, r;
};
bool operator < (const seg &a, const seg &b){
    if (a.r-a.l == b.r-b.l) return a.l > b.l;
    return a.r - a.l < b.r - b.l;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        cnt = 0;
        scanf("%d", &n);
        priority_queue<seg> PQ;
        vt.clear();
        vt.resize(n+1, 0);
        PQ.push({1, n});
        while(!PQ.empty()){
            auto curr = PQ.top(); PQ.pop();
            int cl = curr.l, cr = curr.r;
//            printf("%d %d\n", cl, cr);
            if (cr - cl == -1) continue;
            if ((cr-cl+1)%2) {
                vt[(cl+cr)/2] = ++cnt;
                PQ.push({cl, (cl+cr)/2-1});
                PQ.push({(cl+cr)/2+1, cr});
            }
            else{
                vt[(cl+cr-1)/2] = ++cnt;
                PQ.push({cl, (cl+cr-1)/2-1});
                PQ.push({(cl+cr-1)/2+1, cr});
            }
        }
        for (int i=1;i<=n;i++){
            printf("%d ", vt[i]);
        }
        printf("\n");
    }

    return 0;
}



