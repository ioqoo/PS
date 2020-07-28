#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int N;
vector<pii> arr;
set<int> S;
vector<int> fib;
set<int> fibset;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d", &N);
    int onecnt = 0;
    vector<int> onepos;
    for (int i=1;i<=N;i++){
        int temp;
        scanf("%d", &temp);
        arr.push_back({temp, i});
        S.insert(temp);
        if (temp == 1) {
            onecnt++;
            onepos.push_back(i);
        }
        if (onecnt >= 2){
            printf("%d %d\n", onepos[0], onepos[1]);
            return 0;
        }
    }    
    sort(arr.begin(), arr.end());
    
    int a = 1, b = 1;
    fibset.insert(1);
    fib.push_back(1);
    
    for (int i=0;i<38;i++){
        int c = a+b;
        fibset.insert(c);
        fib.push_back(c);
        a = b;
        b = c;
    }
    
    for (int i=0;i<38;i++){
        int a = fib[i], b = fib[i+1];
        if (S.count(a) && S.count(b)){
            int posa = lower_bound(arr.begin(), arr.end(), make_pair(a, 0)) - arr.begin();
            int posb = lower_bound(arr.begin(), arr.end(), make_pair(b, 0)) - arr.begin();
            printf("%d %d\n", arr[posa].second, arr[posb].second);
            return 0;
        }
    }
    
//    for (int i=0;i<N-1;i++){
//        int curr = arr[i].first;
//        if (!fibset.count(curr)) continue;
//        printf("%d\n", curr);
//        int currpos = lower_bound(fib.begin(), fib.end(), curr) - fib.begin();
//        int next = arr[i+1].first;
//        if (!fibset.count(next)) continue;
//        
//        if (curr == 1 && next == 1) {
//            printf("%d %d\n", arr[i].second, arr[i+1].second);
//            return 0;
//        }
//        int nextpos = lower_bound(fib.begin(), fib.end(), next)- fib.begin();
//        if (nextpos - currpos == 1) {
//            printf("%d %d\n", arr[i].second, arr[i+1].second);
//            return 0;
//        }
//    }
    printf("impossible");
    

    return 0;
}



