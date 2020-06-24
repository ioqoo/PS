#include <bits/stdc++.h>

const int MAX = 100005;
using namespace std;

int N, M;
vector<int> cand;
int solved[MAX], penalty[MAX];
bool isin[MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d %d", &N, &M);
    int t, p;
    for (int j=0;j<M;j++){
        scanf("%d %d", &t, &p);
        if (t == 1){
            solved[1]++;
            penalty[1]+=p;
            vector<int> temp;
//            printf("1 solved : %d / 1 penalty : %d \n", solved[1], penalty[1]);
            for (int i=0;i<cand.size();i++){
                int curr = cand[i];
//                printf("solve %d / penalty %d\n", solved[curr], penalty[curr]);
                if ((solved[curr] > solved[1]) || ((solved[curr] == solved[1]) && (penalty[curr] < penalty[1]))){
                    temp.push_back(curr);
                }
                else{
                    isin[curr] = false;
                }
            }
            cand = temp;
        }
        else{
            solved[t]++;
            penalty[t]+=p;
            if (!isin[t]){
                if (solved[t] > solved[1] || (solved[t] == solved[1] && penalty[t] < penalty[1])){
                    cand.push_back(t);
                    isin[t] = true;
                }
            }
        }
//        for (int n: cand){
//            printf("%d ", n);
//        }
//        printf("\n");
        printf("%d\n", cand.size()+1);
    }

    return 0;
}



