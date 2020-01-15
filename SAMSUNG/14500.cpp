#include <bits/stdc++.h>
#define ll long long
#define MAX 500

using namespace std;

int N, M;
int grid[MAX][MAX];
int ans = 0;
int di1[] = {0, 0, 0, 0};
int dj1[] = {0, 1, 2, 3};
int di2[] = {0, 0, 1, 1};
int dj2[] = {0, 1, 0, 1};
int di3[] = {0, 1, 2, 2};
int dj3[] = {0, 0, 0, 1};
int di4[] = {0, 1, 1, 2};
int dj4[] = {0, 0, 1, 1};
int di5[] = {0, 0, 0, 1};
int dj5[] = {0, 1, 2, 1};

int pl1(int i, int j){
    int ret = 0;
    for (int d=0;d<4;d++){
        int ni = i + di1[d], nj = j + dj1[d];
        printf("%d %d // ", ni, nj);
        if (ni < 0 || ni >= N || nj < 0 || nj >= M){
            return 0;
        }
        ret += grid[ni][nj];
    }
    return ret;
}

int pl2(int i, int j){
    int ret = 0;
    for (int d=0;d<4;d++){
        int ni = i + di2[d], nj = j + dj2[d];
        if (ni < 0 || ni >= N || nj < 0 || nj >= M){
            return 0;
        }
        ret += grid[ni][nj];
    }
    return ret;
}

int pl3(int i, int j){
    int ret = 0;
    for (int d=0;d<4;d++){
        int ni = i + di3[d], nj = j + dj3[d];
        if (ni < 0 || ni >= N || nj < 0 || nj >= M){
            return 0;
        }
        ret += grid[ni][nj];
    }
    return ret;
}

int pl4(int i, int j){
    int ret = 0;
    for (int d=0;d<4;d++){
        int ni = i + di4[d], nj = j + dj4[d];
        if (ni < 0 || ni >= N || nj < 0 || nj >= M){
            return 0;
        }
        ret += grid[ni][nj];
    }
    return ret;
}

int pl5(int i, int j){
    int ret = 0;
    for (int d=0;d<4;d++){
        int ni = i + di5[d], nj = j + dj5[d];
        if (ni < 0 || ni >= N || nj < 0 || nj >= M){
            return 0;
        }
        ret += grid[ni][nj];
    }
    return ret;
}



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &N, &M);
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            scanf("%d %d", &grid[i][j]);
        }
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            //printf("%d %d %d %d %d\n", pl1(i, j), pl2(i, j), pl3(i, j), pl4(i, j), pl5(i, j));
            ans = max(ans, pl1(i, j));
            ans = max(ans, pl2(i, j));
            ans = max(ans, pl3(i, j));
            ans = max(ans, pl4(i, j));
            ans = max(ans, pl5(i, j));
        }
    }
    printf("%d", ans);
    return 0;
}
