#include <bits/stdc++.h>

const int INF = 2e9;
using namespace std;

int N, M, c1, c2;
int ans = 0;
int minval = INF;
vector<int> P, Q;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N, M;
    scanf("%d %d %d %d", &N, &M, &c1, &c2);
    for (int i=0;i<N;i++){
        int temp;
        scanf("%d", &temp);
        P.push_back(temp);
    }
    for (int i=0;i<M;i++){
        int temp;
        scanf("%d", &temp);
        Q.push_back(temp);
    }
    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end());
    
    int a = 0, b = 0;
    while(a<N && b<M){
        if (abs(P[a] - Q[b]) == minval) ans++;
        else if (abs(P[a] - Q[b]) < minval){
            minval = abs(P[a] - Q[b]);
            ans = 1;
        }
        if (a==N-1){
            b++;
        }
        else if (b==M-1){
            a++;
        }
        else{
            int pnext = P[a+1];
            int qnext = Q[b+1];
            if (pnext >= qnext){
                b++;
            }
            else a++;
        }
    }
    printf("%d %d\n", minval + abs(c1 - c2), ans);
    

    return 0;
}



