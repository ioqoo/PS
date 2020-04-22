#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#define MAX 100005
#define pii pair<int, int>

using namespace std;

int N;
vector<pii> arr;
int num[MAX];
map<int, int> mp;
set<int> TT;
vector<int> LIS;
int pos[MAX];
vector<int> ans;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    int a, b;
    for (int i=0;i<N;i++){
        scanf("%d %d", &a, &b);
        arr.push_back(pii(a, b));
        mp[b] = a;
    }
    sort(arr.begin(), arr.end());
    for (int i=0;i<N;i++){
        num[i] = arr[i].second;
        TT.insert(arr[i].second);
    }
    LIS.push_back(num[0]);
    
    for (int i=1;i<N;i++){
        int curr = num[i];
        auto it = lower_bound(LIS.begin(), LIS.end(), curr);
        if (it == LIS.end()){
            pos[i] = LIS.size();
            LIS.push_back(curr);
        }
        else{
            *it = curr;
            pos[i] = it - LIS.begin();
        }
    }
    
    printf("%d\n", N-LIS.size());
    
    int t = LIS.size()-1;
    for (int i=N-1;i>=0;i--){
        if (pos[i] == t){
            ans.push_back(num[i]);
            t--;
        }
    }
    
    
    for (int n: ans){
        if (TT.count(n)) TT.erase(n);
    }
    
    vector<int> fin;
    
    for (auto it=TT.begin();it!=TT.end();it++){
        fin.push_back(mp[*it]);
    }
    sort(fin.begin(), fin.end());
    for (int n: fin){
        printf("%d\n", n);
    }
    

    return 0;
}



