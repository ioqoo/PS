#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define MAX 100005

using namespace std;

int N;
int A[MAX], B[MAX];
vector<int> LIS;
map<int, int> mp;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    int temp;
    for (int i=0;i<N;i++){
        scanf("%d", &temp);
        A[i] = temp;
        mp[temp] = i;
    }
    for (int i=0;i<N;i++){
        scanf("%d", &temp);
        B[i] = mp[temp];
    }
    
    LIS.push_back(B[0]);
    for (int i=1;i<N;i++){
        int curr = B[i];
        auto it = lower_bound(LIS.begin(), LIS.end(), curr);
        if (it == LIS.end()) LIS.push_back(curr);
        else *it = curr;
    }
    
    printf("%d\n", LIS.size());

    return 0;
}



