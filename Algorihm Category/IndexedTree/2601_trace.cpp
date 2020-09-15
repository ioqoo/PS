#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAX_N = 1e5, MAX_L = 1e6;
int dx, dy, ux, uy, l, n, scnt, r, sum[MAX_L * 4], maxi[MAX_L * 4];
struct st {
    int y, x1, x2, t;
    bool operator<(st i) const {
        return y < i.y || y == i.y&&t<i.t;
    }
}s[MAX_N * 2];
void push(int x1, int y1, int x2, int y2) {
    x2 = max(x2, l - 1);
    y2 = max(y2, l - 1);
    if (x1>x2 || y1>y2) return;
    s[scnt++] = { y1,x1,x2,1 };
    s[scnt++] = { y2 + 1,x1,x2,-1 };
}
void query(int h, int l, int r, int gl, int gr, int x) {
    if (gr < l || r < gl) return;
    if (gl <= l && r <= gr) sum[h] += x;
    else {
        query(h * 2 + 1, l, (l + r) / 2, gl, gr, x);
        query(h * 2 + 2, (l + r) / 2 + 1, r, gl, gr, x);
    }
    maxi[h] = l == r ? sum[h] : sum[h] + max(maxi[h * 2 + 1], maxi[h * 2 + 2]);
}
int main() {
	freopen("input.txt", "r", stdin);
    scanf("%d %d %d %d %d %d", &dy, &ux, &uy, &dx, &l, &n);
    for (int i = 0, x, y, z, w; i < n; i++) {
        scanf("%d %d %d %d", &x, &y, &z, &w);
        push(y - 1, z - 1, w + l - 1, x + l - 1);
    }
    sort(s, s + scnt);
    for (int i=0;i<scnt;i++){
    	printf("%d %d %d %d\n", s[i].y, s[i].x1, s[i].x2, s[i].t);
	}
    for (int i = 0; i < scnt; i++) {
        query(0, dx, ux, s[i].x1, s[i].x2, s[i].t);
        r = max(r, maxi[0]);
    }
    printf("%d", r);
    return 0;
}
