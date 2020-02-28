#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define pii pair<int, int>
#define piii pair<int, pii>
#define MAX 100005

using namespace std;


typedef struct Planet{
    int num;
    int x;
    int y;
    int z;
    
}P;

bool cmpx(const P &A, const P &B){
    return A.x < B.x;
}

bool cmpy(const P &A, const P &B){
    return A.y < B.y;
}

bool cmpz(const P &A, const P &B){
    return A.z < B.z;
}

int N;
int p[MAX];
P planets[MAX];
priority_queue<piii, vector<piii>, greater<piii>> PQ;

int find(int a){
    if (p[a] == -1) return a;
    
    return p[a] = find(p[a]);
}

bool merge(int a, int b){
    int roota = find(a);
    int rootb = find(b);
    if (roota == rootb) return false;
    
    p[roota] = rootb;
    return true;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    memset(p, -1, sizeof(p));
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        P temp;
        temp.num = i, temp.x = x, temp.y = y, temp.z = z;
        planets[i] = temp;
    }
    
    sort(planets, planets+N, cmpx);
    for (int i=0;i<N-1;i++){
        P A = planets[i];
        P B = planets[i+1];
        PQ.push(make_pair(abs(A.x - B.x) , pii(A.num, B.num)));
    }

    sort(planets, planets+N, cmpy);
    for (int i=0;i<N-1;i++){
        P A = planets[i];
        P B = planets[i+1];
        PQ.push(make_pair(abs(A.y - B.y) , pii(A.num, B.num)));
    }

    sort(planets, planets+N, cmpz);
    for (int i=0;i<N-1;i++){
        P A = planets[i];
        P B = planets[i+1];
        PQ.push(make_pair(abs(A.z - B.z) , pii(A.num, B.num)));
    }        
    
    int edge_cnt = 0;
    int ans = 0;
    while (edge_cnt < N-1){
        auto pp = PQ.top();
        PQ.pop();
        int w = pp.first;
        int a = pp.second.first, b = pp.second.second;
        if (merge(a, b)) {
            edge_cnt++;
            ans += w;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
