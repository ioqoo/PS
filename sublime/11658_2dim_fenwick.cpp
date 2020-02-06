#include <bits/stdc++.h>

using namespace std;

int n, m;
int f_tree[1111][1111];

int sum(int x, int y){
	int ret = 0;
	for (int i=x;i>0;i-=(i&-i)){
		for (int j=y;j>0;j-=(j&-j)){
			ret += f_tree[i][j];
		}
	}
	return ret;
}

void update(int x, int y, int diff){
	for (int i=x;i<=n;i+=(i&-i)){
		for (int j=y;j<=n;j+=(j&-j)){
			f_tree[i][j] += diff;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			int temp;
			scanf("%d", &temp);
			update(i, j, temp);
		}
	}

	for (int i=0;i<m;i++){
		int op;
		scanf("%d", &op);
		if (op==0) { // update
			int x, y, val;
			scanf("%d %d %d", &x, &y, &val);
			int val_0 = sum(x, y) - sum(x-1, y) - sum(x, y-1) + sum(x-1, y-1);
			update(x, y, val - val_0);
		}
		else {
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			printf("%d\n", sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1));
		}
	}
}