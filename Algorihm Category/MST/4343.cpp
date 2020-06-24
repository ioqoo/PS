#include <bits/stdc++.h>
#define pii pair<int, int>
#define pdii pair<double, pii>
#define ll long long

using namespace std;

struct co {
	int x;
	int y;
};

int n, m;
co grid[550];
int p[550];

int find(int a) {
	if (p[a] == -1) return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b) {
	int roota = find(a);
	int rootb = find(b);
	if (roota == rootb) return false;
	p[roota] = rootb;
	return true;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
	int t;
	scanf("%d", &t);
	while(t--) {
		priority_queue<pdii> pq;
		scanf("%d %d", &n, &m);
		memset(p, -1, sizeof(p));
		
		for (int i=1;i<=m;i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			grid[i].x = x;
			grid[i].y = y;
		}
		for (int i=1;i<=m;i++) {
			for (int j=i+1;j<=m;j++) {
				int xdist = abs((grid[i].x - grid[j].x)) * abs((grid[i].x - grid[j].x));
				int ydist = abs((grid[i].y - grid[j].y)) * abs((grid[i].y - grid[j].y));
				double dist = sqrt(xdist + ydist);
				pq.push(make_pair(-dist,make_pair(i,j)));
			}
		}
		double ans;
		int first_value;
		int second_value;
		while (1) {
			ans = -pq.top().first;
			first_value = pq.top().second.first;
			second_value = pq.top().second.second;
			pq.pop();
			if (find(first_value) != find(second_value)){
			    merge(first_value, second_value);
			    n--;
            }
			if (n == 0)
				break;
		}
		printf("%.2f\n", ans);
	}
}
