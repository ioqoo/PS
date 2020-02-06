#include <bits/stdc++.h>
#define MAX 10005
#define ll long long

using namespace std;

int N;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);

    scanf("%d", &N);

    int mid;
    priority_queue<int, vector<int>, greater<int>> incPQ;
    priority_queue<int> decPQ;

    for (int i=1;i<=N;i++){
        int curr;
        scanf("%d", &curr);
        if (i==1){
            mid = curr;
        }
        else{
            if (curr >= mid) incPQ.push(curr);
            else decPQ.push(curr);

            if (i%2){
                if (incPQ.size() > decPQ.size()){
                    decPQ.push(mid);
                    mid = incPQ.top();
                    incPQ.pop();
                }
                else if (incPQ.size() < decPQ.size()){
                    incPQ.push(mid);
                    mid = decPQ.top();
                    decPQ.pop();
                }
            }
            else{
                if (incPQ.size() < decPQ.size()){
                    printf("%d\n", decPQ.top());
                    continue;
                }
            }
        }
        printf("%d\n", mid);
    }

    return 0;
}
