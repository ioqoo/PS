#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000000000000LL
#define MAX 987654321
#define MAX_LEN 100001

using namespace std;

//https://www.acmicpc.net/problem/2934
//ftree를 배열처럼 쓰기
//Fenwick은 결국 구간합을 빠르게 구하기 위해 사용

int n;
ll f_tree[MAX_LEN];

int sum(int i){
	int ret = 0;
	while (i>0){
		ret += f_tree[i];
		i -= (i & -i);
	}
	return ret;
}

void update(int i, int diff){
	while (i < MAX_LEN){
		f_tree[i] += diff;
		i += (i & -i);
	}
}

int main() {
	scanf("%d", &n);
	for (int i=0;i<n;i++){
		int a, b;
		scanf("%d %d", &a, &b);

		int a_val = sum(a);
		int b_val = sum(b);

		update(a, -a_val);
		update(a+1, a_val);
		update(b, -b_val);
		update(b+1, b_val);

		update(a+1, 1);
		update(b, -1);

		printf("%d\n", a_val + b_val);
	}
}

