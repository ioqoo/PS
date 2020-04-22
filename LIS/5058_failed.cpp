#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define MAX 20005
#define pii pair<int, int>
#define piii pair<pii, int>

using namespace std;

int T, N, a, b;
vector<piii> doll;
vector<piii> dollstart;
pii dollarr[MAX];
bool isnotfree[MAX];
int ans;

bool cmp(const piii a, const piii b){
    if (a.first.second == b.first.second) return a.first.first < b.first.first;
    else return a.first.second > b.first.second;
}

bool cmp2(const piii a, const piii b){
    if (a.first.first == b.first.first) return a.first.second > b.first.second;
    else return a.first.first < b.first.first;
}

bool ubcmp(const piii a, const piii b){
    return a.first.first < b.first.first;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &T);
    while(T--){
        
        scanf("%d", &N);
        ans=0;
        doll.clear();
        dollstart.clear();
        fill(dollarr, dollarr+N, pii());
        memset(isnotfree, 0, sizeof(isnotfree));
        for (int i=0;i<N;i++){
            scanf("%d %d", &a, &b);
            doll.push_back(make_pair(pii(a, b), i));
            dollstart.push_back(make_pair(pii(a, b), i));
            dollarr[i] = {a, b};
        }
        
        sort(doll.begin(), doll.end(), cmp);
        sort(dollstart.begin(), dollstart.end(), cmp2);
        
        for (auto p: dollstart){
            auto curr_doll = p;
            if (isnotfree[curr_doll.second]) continue;
            isnotfree[curr_doll.second] = true;
            ans++;
            while(1){
                printf("curr_doll : %d %d // ", curr_doll.first.first, curr_doll.first.second);
                for (auto pp: doll){
                    printf("%d %d // ", pp.first.first, pp.first.second);
                }
                printf("\n");
                auto it = upper_bound(doll.begin(), doll.end(), curr_doll, ubcmp);
                if (it == doll.end()) break;
                isnotfree[(*it).second] = true;
                (*it).first.first = curr_doll.first.first;
                curr_doll = (*it);
            }
            printf("\n");
        }
        
        printf("%d\n", ans);
        
    }

    return 0;
}



