#include <bits/stdc++.h>


using namespace std;

struct point{
    int pos, dir, status, radius;
    // dir :: 0 -> left, 1 -> right
    // status :: 1 -> initial, 2-> succesfully partitioning
    //           3 -> partition failed
    point(int pos1, int dir1, int radius1){
        pos = pos1;
        dir = dir1;
        status = 1;
        radius = radius1;
    }
    bool operator < (const point B){
        if (pos == B.pos) {
            if (dir != B.dir) {
                return dir > B.dir;
            }
            return radius > B.radius;
        }
        return pos < B.pos;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N;
    scanf("%d", &N);
    
    vector<point> vt;
    for (int i=0;i<N;i++){
        int x, r;
        scanf("%d %d", &x, &r);
        int left = x-r, right = x+r;
        vt.push_back({left, 0, r});
        vt.push_back({right, 1, r});
    }
    sort(vt.begin(), vt.end());
    
    int ans = 0;
    stack<point> st;
    int lastpos = 0;
    for (auto curr: vt){
        if (st.empty()) {
            st.push(curr);
            lastpos = curr.pos;
            continue;
        }
        if (curr.dir == 0){ // left
            if (st.top().pos == curr.pos){
                st.top().status = 2;
            }
            else{
                if (lastpos != curr.pos){
                    st.top().status = 3;
                }
            }
            st.push(curr);
            lastpos = curr.pos;
        }
        else { // right
            if (st.top().status == 1){
                ans++;
            }
            else if (st.top().status == 2){
                if (lastpos == curr.pos){
                    ans += 2;
                }
                else {
                    ans++;
                }
            }
            else{
                ans++;
            }
            st.pop();
            lastpos = curr.pos;
        }
    }
        printf("%d\n", ans+1);
    

    return 0;
}



