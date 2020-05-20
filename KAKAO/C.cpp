#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    int n, m;
    scanf("%d", &n);
    vector<int> scores;
    for (int i=0;i<n;i++){
        int temp;
        scanf("%d", &temp);
        scores.push_back(temp);
    }
    for (int i=0;i<n;i++){
        scores[i] *= -1;
    }
    
    scanf("%d", &m);
    vector<int> alice;
    for (int i=0;i<m;i++){
        int temp;
        scanf("%d", &temp);
        alice.push_back(-temp);
    }
    
    scores.erase(unique(scores.begin(), scores.end()), scores.end());
    for (auto n: alice){
        printf("%d\n", lower_bound(scores.begin(), scores.end(), n) - scores.begin());
    }

    return 0;
}



