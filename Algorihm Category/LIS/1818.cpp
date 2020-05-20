#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 200005

using namespace std;

int N;
int book[MAX];
vector<int> LIS;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        scanf("%d", &book[i]);
    }
    
    LIS.push_back(book[0]);
    for (int i=1;i<N;i++){
        int curr = book[i];
        auto it = lower_bound(LIS.begin(), LIS.end(), curr);
        if (it == LIS.end()) LIS.push_back(curr);
        else *it = curr;
    }
    
    printf("%d\n", N-LIS.size());

    return 0;
}



