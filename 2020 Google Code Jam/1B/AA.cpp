#include <bits/stdc++.h>

#define pii pair<int, int>
#define piis pair<pii, string>
#define ll long long

#define MAX 33

using namespace std;

int T;
//string ans;
char dir[] = {'W', 'E', 'S', 'N'};
char ans[MAX];
string finans;

void dfsH(ll dest, ll curr, vector<int> &remain, int pos, string way, bool rev){
    cout << "dest : " << dest << " / curr : " << curr << " / way : " << way << endl;
    if (pos >= remain.size()) return;
    if (dest == curr) {
        finans = way;
        return;
    }
    if (rev){
        dfsH(dest, curr - (1LL<<remain[pos]), remain, pos+1, way + 'E', rev);
        dfsH(dest, curr + (1LL<<remain[pos]), remain, pos+1, way + 'W', rev);
    }
    else {
        dfsH(dest, curr - (1LL<<remain[pos]), remain, pos+1, way + 'W', rev);
        dfsH(dest, curr + (1LL<<remain[pos]), remain, pos+1, way + 'E', rev);
    }
    
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> T;
    for (int t=1;t<=T;t++){
        int ox, oy;
        cin >> ox >> oy;
        int x = abs(ox), y = abs(oy);
        if (x < y) {
            ll n = 1;
            int pos = 0;
            while(n < y){
                if (n & y) {
                    if (oy > 0) ans[pos] = 'E';
                    else ans[pos] = 'W';
                }
                n = n << 1;
                pos++;
            }
            
            vector<int> remain;
            n = 1;
            pos = 0;
            while(n < y){
                if (ans[pos] == '\0') remain.push_back(pos);
                n = n << 1;
                pos++;
            }
            
            n = 1;
            pos = 0;
            while(n < x){
                n = n << 1;
                pos++;
            }
            
            ll sub = n - x;
            
            if (ox > 0){
                dfsH(sub, 0, remain, 0, "", false);
            }
            else {
                dfsH(sub, 0, remain, 0, "", true);
            }
            
            if (finans == "") cout << "Case #" << t << ": " << "IMPOSSIBLE\n";
            else cout << "Case #" << t << ": " << finans << "\n";
            
        
            
            // have to make sub with elements in remain
            
             
            
            
        }
    
        
        
//        
//        int ox, oy;
//        cin >> ox >> oy;
//        int x = abs(ox), y = abs(oy);
//        
//        int n = 1;
//        int pos = 0;
//        while(n < x){
//            if (n & x) {
//                ans[pos] = 'E';
//            }
//            n = n << 1;
//            pos++;
//        }
//        
//        vector<int> remain;
//        n = 1;
//        pos = 0;
//        while(n<x){
//            if (ans[pos] == '\0') remain.push_back(pos);
//            n = n << 1;
//            pos++;
//        }
//        
//        n = 1;
//        pos = 0;
//        while(n < y){
//            n = n << 1;
//            pos++;
//        }
//        
//        int remain = 0;
//        for (int n: remain){
//            
//            remain += (1<<n);
//        }
//        
//        if ( (1 << pos) - remain == y ) {
//            
//        }
//        
//        for (int n: remain){
//            cout << n << endl;
//        }
//        
//        
        
//        if (succ) cout << "Case #" << t << ": " << ans << "\n";
//        else cout << "Case #" << t << ": IMPOSSIBLE\n";
        
        
        
    }

    return 0;
}



