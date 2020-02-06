#include <bits/stdc++.h>
#define MAX 10005
#define ll long long

using namespace std;

int N;
priority_queue<int> PQ;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);

    scanf("%d", &N);
    for (int i=0;i<N;i++){
        int n;
        scanf("%d", &n);
        if (n == 0){
            if (PQ.empty()){
                printf("0\n");
            }
            else{
                printf("%d\n", PQ.top());
                PQ.pop();
            }
        }
        else{
            PQ.push(n);
        }
    }


    return 0;
}
