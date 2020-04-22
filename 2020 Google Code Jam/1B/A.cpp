#include <bits/stdc++.h>

#define pii pair<int, int>
#define piis pair<pii, string>

using namespace std;

int T;
string ans;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'W', 'E', 'S', 'N'};


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> T;
    for (int t=1;t<=T;t++){
        int x, y;
        cin >> x >> y;
        int cx = 0, cy = 0;
        queue<piis> Q;
        int i = 1;
        Q.push(make_pair(pii(0, 0), ""));
        bool succ = false;
        for (int i=1;i<=128;i*=2){
            int curr_Qsize = Q.size();
            for (int z=0;z<curr_Qsize;z++){
                auto p = Q.front();
                auto curr = p.first;
                int currx = curr.first, curry = curr.second;
                string way = p.second;
                Q.pop();
                for (int d=0;d<4;d++){
                    int nx = currx + dx[d]*i, ny = curry + dy[d]*i;
                    char currdir = dir[d];
                    if (nx == x && ny == y) {
                        succ = true;
                        ans = way + currdir;
                        break;
                    }
                    Q.push(make_pair(pii(nx, ny), way + currdir));
                }
                if (succ) break;
            }
        }
        if (succ) cout << "Case #" << t << ": " << ans << "\n";
        else cout << "Case #" << t << ": IMPOSSIBLE\n";
        
        
        
    }

    return 0;
}



