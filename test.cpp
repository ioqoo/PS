#include <iostream>
#include <cmath>

#define MAX 1000000

using namespace std;

int N;
int tree[1<<21];
int leaf_size;

void update(int i, int diff){
	i += leaf_size;
	tree[i] += diff;
	while(i>1){
		i/=2;
		tree[i] = tree[i*2] + tree[i*2+1];
	}
}

int find(int node, int s, int e, int remain){
	if (s==e) return s;
	
	int mid = (s+e)/2;
	int left_child = tree[node*2];
	if (remain > left_child){
		return find(node*2+1, mid+1, e, remain - left_child);
	}
	else{
		return find(node*2, s, mid, remain);
	}
	
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	leaf_size = 1 << (int)(ceil(log2(MAX)));
	
	scanf("%d", &N);
	int op, b, c, pos;
	for (int i=0;i<N;i++){
		scanf("%d", &op);
		if (op == 1){
			scanf("%d", &b);
			pos =  find(1, 0, leaf_size-1, b);
			printf("%d\n", pos+1);
			update(pos, -1);
		}
		else {
			scanf("%d %d", &b, &c);
			update(b-1, c);
		}
	}
	
	
	return 0;
}
