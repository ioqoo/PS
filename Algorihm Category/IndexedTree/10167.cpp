#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

struct point{
    ll x, y, w;
    bool operator < (const point &A){
        if (y == A.y) return x < A.x;
        return y < A.y;
    }
}; 

struct Node{
    ll sum, l, r, m;
    
    ll Max(){
        return max(max(sum, l), max(r, m));
    }
};

Node tree[8300];
int N;
vector<point> P;
vector<ll> xco;
vector<ll> yco;


void clear(){
    for (int i=0;i<8300;i++){
        tree[i].sum = tree[i].l = tree[i].r = tree[i].m = 0;
    }
}

Node updatenode(Node &A, Node &B){
    Node ret;
    ret.sum = A.sum + B.sum;
    ret.l = max(A.sum + B.l, max(A.l, A.sum));
    ret.r = max(B.sum + A.r, max(B.r, B.sum));
    ret.m = max(A.r + B.l, max(A.m, B.m));
    return ret;    
}

void update(int ind, ll val){
    ind += leaf_size;
    tree[ind].l = tree[ind].r = tree[ind].m = tree[ind].sum += val;
    while(ind > 1){
        ind /= 2;
        tree[ind] = updatenode(tree[ind*2], tree[ind*2+1]);
    }
}

ll getind(vector<ll> &vt, ll val){
    return lower_bound(all(vt), val) - vt.begin();
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);

    ll x, y, w;
    for (int i=0;i<N;i++){
        scanf("%lld %lld %lld", &x, &y, &w);
        P.push_back({x, y, w});
        xco.push_back(x);
        yco.push_back(y);
    }
    
    // grid compression 
    sort(all(xco));
    sort(all(yco));
    xco.erase(unique(all(xco)), xco.end());
    yco.erase(unique(all(yco)), yco.end());
    for (int i=0;i<N;i++){
        P[i].x = getind(xco, P[i].x);
        P[i].y = getind(yco, P[i].y);
    }
    
    sort(all(P));

    
    int yrange = P.back().y;
    
    int s = 0; // y1 
    int i = 0; // y2
    ll ret = 0;
    while(s <= yrange){
        i = 0;
        clear();
        while(i < N){
            if (P[i].y < s) { // find y2
                i++;
                continue;
            }
            update(P[i].x, P[i].w);
            if (i+1 == N || P[i].y != P[i+1].y){
                ret = max(ret, tree[1].Max());
            }
            i++;
        }
        s++;
    }
    
    printf("%lld\n", ret);
    
    return 0;
}



