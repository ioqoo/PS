#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N;
    scanf("%d", &N);
    vector<int> vt;
    for (int i=0;i<N;i++){
        int temp;
        scanf("%d", &temp);
        vt.push_back(temp);
    }
    sort(vt.begin(), vt.end());
    
    int q_ind = 0;
    for (int i=0;i<=N;i++){
        int lpos = lower_bound(vt.begin(), vt.end(), i) - vt.begin();
        int upos = upper_bound(vt.begin(), vt.end(), i) - vt.begin();
        if (lpos <= i && N-i <= upos){
            q_ind = i;
            break;
        }
    }
    printf("%d\n", q_ind);
    
    

    return 0;
}



