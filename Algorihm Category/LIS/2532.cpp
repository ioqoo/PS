#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
#define MAX 500005

using namespace std;

int N;
vector<pii> ani;
vector<int> LIS;

bool cmp(const pii A, const pii B){
    if (A.first == B.first) return A.second > B.second;
    return A.first < B.first;
}

bool lb_comp(const int a, const int b){
    return a >= b;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    int num, a, b;
    for (int i=0;i<N;i++){
        scanf("%d %d %d", &num, &a, &b);
        ani.push_back(pii(a, b));
    }
    
    sort(ani.begin(), ani.end(), cmp);
    ani.erase(unique(ani.begin(), ani.end()), ani.end());
    LIS.push_back(ani[0].second);
    for (int i=1;i<N;i++){
        int curr = ani[i].second;
        auto it = lower_bound(LIS.begin(), LIS.end(), curr, lb_comp);
        if (it == LIS.end()) LIS.push_back(curr);
        else *it = curr;
        
    }
    printf("%d\n", LIS.size());
    
    

    return 0;
}



