#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define MAX 10

using namespace std;

int N;
int grid[MAX][MAX];
vector<int> avail;
int ans;

bool check(){
    bool remain = false;

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (grid[i][j] == 1) {
                remain = true;
                break;
            }
        }
    }
    return remain;
}

pii convert(int i){
    return pii(i/N, i%N);
}

void promis(int a, int b, int num){
    for (int i=-9;i<=9;i++){
        int ni = a + i, nj = b - i;
        if (0 <= ni && ni < N && 0 <= nj && nj < N) {
            if (grid[ni][nj] == 1) {
                grid[ni][nj] = num;
            }
        }
        nj = b + i;
        if (0 <= ni && ni < N && 0 <= nj && nj < N) {
            if (grid[ni][nj] == 1) {
                grid[ni][nj] = num;
            }
        }
    }
}

void undo(int a, int b, int num){
    for (int i=-9;i<=9;i++){
        int ni = a + i, nj = b - i;
        if (0 <= ni && ni < N && 0 <= nj && nj < N) {
            if (grid[ni][nj] == num) grid[ni][nj] = 1;
        }
        nj = b + i;
        if (0 <= ni && ni < N && 0 <= nj && nj < N) {
            if (grid[ni][nj] == num) grid[ni][nj] = 1;
        }
    }
}

void bt(int n, int num){
    int pos = avail[n];

    if (n >= avail.size()){
        ans = max(ans, num-2);
        return;
    }

    auto p = convert(pos);
    int i = p.first, j = p.second;

    if (grid[i][j] == 1){
        promis(i, j, num);
        bt(n+1, num+1);
        undo(i, j, num);
    }
    bt(n+1, num);
}



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            int temp;
            scanf("%d", &temp);
            grid[i][j] = temp;
            if (grid[i][j] == 1) avail.push_back(i*10 + j);
        }
    }

    for (int i=0;i<avail.size();i++){
        bt(i, 2);
    }

    printf("%d\n", ans);
}
