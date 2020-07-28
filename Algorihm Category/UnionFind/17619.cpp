#include <bits/stdc++.h>

const int MAX = 100005;
using namespace std;

int N, Q;

struct Log{
    int num, x1, x2;
    bool operator < (Log b){
        if (x1 == b.x1) return x2 < b.x2;
        return x1 < b.x1;
    }
};

int p[MAX];

int find(int node){
    if (p[node] == -1) return node;
    return p[node] = find(p[node]);
}

void merge(int nodea, int nodeb){
    int roota = find(nodea);
    int rootb = find(nodeb);
    if (roota == rootb) return;
    p[roota] = rootb;
    return;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d %d", &N, &Q);
    memset(p, -1, sizeof(p));
    vector<Log> arr;
    for (int i=1;i<=N;i++){
        int x1, x2, y;
        scanf("%d %d %d", &x1, &x2, &y);
        arr.push_back({i, x1, x2});
    }
    sort(arr.begin(), arr.end());
    
    int inter_l = arr[0].x1, inter_r = arr[0].x2;
    for (int i=1;i<N;i++){
        if (arr[i].x1 <= inter_r){
            merge(arr[i-1].num, arr[i].num);
            inter_l = arr[i].x1, inter_r = max(inter_r, arr[i].x2);
        }
        else{
            inter_l = arr[i].x1, inter_r = arr[i].x2;
        }
//        printf("%d %d\n", inter_l, inter_r);
    }
    
    for (int i=0;i<Q;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if (find(a) == find(b)){
            printf("1\n");
        }
        else printf("0\n");
    }
    
    

    return 0;
}



