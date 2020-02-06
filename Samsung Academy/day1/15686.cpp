#include <bits/stdc++.h>
#define MAX 53
#define pii pair<int, int>
#define INF 987654321

using namespace std;

int N, M;
int grid[MAX][MAX];
bool choice[13];
int ans = INF;
vector<pii> house;
vector<pii> chicken;

int taxi(pii A, pii B){
    return (abs(A.first - B.first) + abs(A.second - B.second));
}

void dfs(int pos, int cnt){
    if (cnt == M){

        vector<pii> survive;
        for (int i=0;i<13;i++){
            if (choice[i]) survive.push_back(chicken[i]);
        }

        int ret = 0;
        for (auto h: house){
            int temp = INF;
            for (auto c: survive){
                temp = min(temp, taxi(h, c));
            }
            ret += temp;
        }
        ans = min(ans, ret);
        return;
    }

    for (int j = pos + 1; j < chicken.size(); j++){
        choice[j] = true;
        dfs(j, cnt+1);
        choice[j] = false;
    }
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &N, &M);
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            int temp;
            scanf("%d", &temp);
            grid[i][j] = temp;
            if (temp == 1) house.push_back(pii(i, j));
            else if (temp == 2) chicken.push_back(pii(i, j));
        }
    }

    int chic_size = chicken.size();
    for (int i=0;i<chic_size;i++){
        choice[i] = true;
        dfs(i, 1);
        choice[i] = false;
    }

    printf("%d\n", ans);



}
