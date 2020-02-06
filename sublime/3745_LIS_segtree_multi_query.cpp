#include <iostream>
#include <cstdio>
#include <string>
#include <cstring> // memset, memcpy
#include <algorithm>
//#include <stack>
//#include <queue>
//#include <deque>
#include <vector>
//#include <functional>
//#include <map>
//#include <set>
#include <utility> // pair
#define pii pair<int, int>

using namespace std;

int N;
vector<pii> num_and_pair;
int seg_tree[1<<21]; 
int leaf_size=1;

bool compare (pii a, pii b){
	if (a.first == b.first) {
		return a.second > b.second;
	}
	else return a.first < b.first;
}

void update(int i, int val){
	i += leaf_size;
	seg_tree[i] = val;
	while (i>1) {
		i /= 2;
		seg_tree[i] = max(seg_tree[i*2], seg_tree[i*2+1]);
	}
}

void construct(){
	for (int i=leaf_size-1;i>0;i--){
		seg_tree[i] = max(seg_tree[i*2], seg_tree[i*2+1]);
	}
}

int find_max(int L, int R, int nodenum, int nodeL, int nodeR){
	if (R < nodeL || nodeR < L) return -1;
	if (L <= nodeL && nodeR <= R) return seg_tree[nodenum];
	int mid = (nodeL + nodeR) / 2;
	return max(find_max(L, R, nodenum*2, nodeL, mid), find_max(L, R, nodenum*2+1, mid+1, nodeR));
}

int main(){
	while (scanf("%d", &N)!=EOF){
		num_and_pair.clear();
		leaf_size = 1;
		while (leaf_size < N){
			leaf_size *= 2;
		}
		memset(seg_tree, 0, sizeof(seg_tree));


		for (int i=0;i<N;i++){
			int temp=0;
			scanf("%d", &temp);
			pii p(temp, i);
			num_and_pair.push_back(p);
		}
		sort(num_and_pair.begin(), num_and_pair.end(), compare);

		for (int i=0;i<N;i++){
			int ind = num_and_pair[i].second;
			update(ind, find_max(0, ind, 1, 0, leaf_size-1)+1);
			// for (int i=1;i<2*leaf_size;i++){
			// 	printf("%d ", seg_tree[i]);
			// }
			// printf("\n");		
		}


		printf("%d\n", seg_tree[1]);
	}		
}