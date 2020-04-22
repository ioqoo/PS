#include <iostream>
#include <cstring>
#include <algorithm>

#define pii pair<int, int>
#define MAX 1444

using namespace std;

int T, N, s, e;
bool J[MAX], C[MAX];
vector<pair<pii, int>> works;
char ans[1005];
string no = "IMPOSSIBLE\n";

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> T;
    for (int t=1;t<=T;t++){
        cout << "Case #" << t << ": ";
        cin >> N;
        memset(J, 0, sizeof(J));
        memset(C, 0, sizeof(C));
        memset(ans, 0, sizeof(ans));
        works.clear();
        
        for (int i=1;i<=N;i++){
            cin >> s >> e;
            works.push_back(make_pair(pii(s, e), i));
        }
        sort(works.begin(), works.end());
        bool succ_final = true;
        for (auto p: works){
            int curr_s = p.first.first, curr_e = p.first.second;
            int curr_num = p.second;
            bool succ_J = true;
            for (int i=curr_s;i<curr_e;i++){
                if (J[i]) {
                    succ_J = false;
                    break;
                }
            }
            if (succ_J) {
                fill(J+curr_s, J+curr_e, 1);
                ans[curr_num] = 'J';
                continue;
            }
            bool succ_C = true;
            for (int i=curr_s;i<curr_e;i++){
                if (C[i]){
                    succ_C = false;
                    break;
                }
            }
            if (succ_C) {
                fill(C+curr_s, C+curr_e, 1);
                ans[curr_num] = 'C';
                continue;
            }
            else{
                succ_final = false;
                break;
            }
        }
        if (succ_final){
            for (int i=1;i<=N;i++){
                cout << ans[i];
            }
            cout << "\n";
        }
        else{
            cout << no;
        }
    }
    

    return 0;
}

