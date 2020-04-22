#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 10005

using namespace std;

int N, x, y, ans;
int tree[MAX];


struct p{
    int x, y;
    bool operator < (const p &q){
        if (p.y == q.y) return p.x < q.x;
        return p.y < q.y;
    }
};

p 


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    return 0;
}



