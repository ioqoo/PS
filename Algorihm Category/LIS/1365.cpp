#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100005

using namespace std;

int N;
int num[MAX];
vector<int> LIS;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        scanf("%d", &num[i]);
    }
    
    LIS.push_back(num[0]);
    for (int i=1;i<N;i++){
        int curr = num[i];
        if (LIS.back() < curr) LIS.push_back(curr);
        else {
            auto it = lower_bound(LIS.begin(), LIS.end(), curr);
            *it = curr;
        }
    }
    printf("%d\n", N-LIS.size());
    

    return 0;
}



