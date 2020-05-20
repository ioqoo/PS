#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define MAX 10005

using namespace std;

int N;
map<int, int> mp;
map<int, int> mp_rev;
int num[MAX];
vector<int> LIS;
int pos[MAX];
vector<int> ans;
vector<int> fin;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    int temp;
    for (int i=0;i<N;i++){
        scanf("%d", &temp);
        mp[temp] = i;
        mp_rev[i] = temp;
    }
    
    for (int i=0;i<N;i++){
        scanf("%d", &temp);
        num[i] = mp[temp];
    }
    LIS.push_back(num[0]);
    for (int i=1;i<N;i++){
        int curr = num[i];
        auto it = lower_bound(LIS.begin(), LIS.end(), curr);
        if (it == LIS.end()) {
            pos[i] = LIS.size();
            LIS.push_back(curr);
        }
        else{
            *it = curr;
            pos[i] = it - LIS.begin();
        }
    }
    
    
    printf("%d\n", LIS.size());
    int t = LIS.size()-1;
    for (int i=N-1;i>=0;i--){
        if (pos[i] == t){
//            printf("%d ", i);
            ans.push_back(mp_rev[num[i]]);
            t--;
        }
    }
    for (auto it=ans.rbegin();it!=ans.rend();it++){
        fin.push_back(*it);
    }
    sort(fin.begin(), fin.end());
    for (int n:fin){
        printf("%d ", n);
    }
    
    

    return 0;
}


