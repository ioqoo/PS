#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int N, M;
set<int> s;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);
    for (int i=0;i<N;i++){
        int temp;
        scanf("%d", &temp);
        s.insert(temp);
    }
    scanf("%d", &M);
    for (int i=0;i<M;i++){
        int temp;
        scanf("%d", &temp);
        if (s.count(temp)) printf("1\n");
        else printf("0\n");
    }

    return 0;

}
