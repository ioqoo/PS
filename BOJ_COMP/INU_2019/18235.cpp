// https://www.acmicpc.net/problem/18235

#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int N, A, B;
vector<int> day_5[500005];
queue<pii> q;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d %d", &N, &A, &B);
    q.push(pii(A, 0));
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int pos = p.first, day_a = p.second;
        int dx[] = {1<<day_a, -(1<<day_a)};
        for (int i=0;i<2;i++){
            int nx = pos + dx[i];
            if (1 <= nx && nx <= N){
                day_5[nx].push_back(day_a + 1);
                q.push(pii(nx, day_a + 1));
            }

        }
    }
    q.push(pii(B, 0));
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int pos = p.first, day_b = p.second;
        int dx[] = {1<<day_b, -(1<<day_b)};
        for (int i=0;i<2;i++){
            int nx = pos + dx[i];
            if (1 <= nx && nx <= N){
                for (int j=0;j<day_5[nx].size();j++){
                    if (day_b + 1 == day_5[nx][j]){
                        printf("%d\n", day_b + 1);
                        return 0;
                    }
                }
                q.push(pii(nx, day_b + 1));
            }
        }
    }
//    for (int i=1;i<=N;i++){
//        printf("%d %d\n", day[i].first, day[i].second);
//    }
    printf("-1");
}
