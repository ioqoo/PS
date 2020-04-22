#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 2005

using namespace std;

int N;
int arr[MAX];
vector<int> IS;
vector<int> DS;
vector<int> LIS;
vector<int> LDS;

bool cmp(const int a, const int b){
    return a >= b;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    if (N==0) {
        printf("0\n");
        return 0;
    }
    for (int i=0;i<N;i++){
        scanf("%d", &arr[i]);
    }
    
    int ans = 0;
    for (int i=0;i<N;i++){
        IS.clear(); DS.clear(); LIS.clear(); LDS.clear();
        int start = arr[i];
        IS.push_back(start); DS.push_back(start);
        for (int j=i+1;j<N;j++){
            if (start < arr[j]) IS.push_back(arr[j]);
            else DS.push_back(arr[j]);
        }
        for (auto curr: IS){
            auto it = lower_bound(LIS.begin(), LIS.end(), curr);
            if (it == LIS.end()) LIS.push_back(curr);
            else *it = curr;
        }
        
        for (auto curr: DS){
            auto it = lower_bound(LDS.begin(), LDS.end(), curr, cmp);
            if (it == LDS.end()) LDS.push_back(curr);
            else *it = curr;
        }
        int temp = LIS.size() + LDS.size() - 1;
        ans = max(ans, temp);
    }
    printf("%d\n", ans);
    
    return 0;
}



