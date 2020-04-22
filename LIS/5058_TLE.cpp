#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>

#define MAX 20005
#define pii pair<int, int>

using namespace std;

bool piicmp(const pii a, const pii b){
    if (a.first < b.first && a.second < b.second) return true;
    else return false;
}


int T, M, x, y;
vector<pii> doll;
vector<pii> LIS[MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &T);
    
    
    
    while(T--){
        scanf("%d", &M);
        doll.clear();
        for (int i=0;i<M;i++){
            LIS[i].clear();
        }
        for (int i=0;i<M;i++){
            scanf("%d %d", &x, &y);
            doll.push_back(pii(x, y));
        }
        
        sort(doll.begin(), doll.end());
        LIS[0].push_back(doll[0]);
        for (int i=1;i<M;i++){
            pii curr = doll[i];
            for (int j=0;j<M;j++){
//                printf("j: %d\n", j);
                if (LIS[j].empty()) {
                    LIS[j].push_back(curr);
                    break;
                }
                auto it = lower_bound(LIS[j].begin(), LIS[j].end(), curr, piicmp);
                if (it == LIS[j].end()) {
                    pii pre = LIS[j].back();
//                    printf("end -- pre : %d %d\n", pre.first, pre.second);
                    if (curr.first > pre.first && curr.second > pre.second){
                        LIS[j].push_back(curr);
                        break;
                    }
                }
                else {
                    pii pre = *it;
//                    printf("pre : %d %d\n", pre.first, pre.second);
                    if (curr.first < pre.first && curr.second < pre.second){
                        *it = curr;
                        break;
                    }
                }
            }
//            for (int i=0;i<M;i++){
//                printf("LIS # %d : ", i);
//                for (auto p: LIS[i]){
//                    printf("%d %d/ ", p.first, p.second);
//                }
//                printf("\n");
//            }
        }
        
        
        int ans = 0;
        for (int i=0;i<M;i++){
            if (!LIS[i].empty()){
                ans++;
            }
            else break;
        }
        printf("%d\n", ans);
        
        
    }

    return 0;
}



