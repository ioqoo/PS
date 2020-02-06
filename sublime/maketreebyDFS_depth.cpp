#include <iostream>
#include <cstdio>
//#include <string>
//#include <cstdlib> // atoi
//#include <cmath>
//#include <cstring> // memset, memcpy
#include <algorithm>
//#include <stack>
//#include <queue>
//#include <deque>
#include <vector>
//#include <functional>
//#include <map>
//#include <set>
//#include <utility> // pair
//#define ll long long
//#define pii pair<int, int>

using namespace std;

int N, M;
vector<int> graph[10000];
int parent[10000];
int depth[10000];

void maketreebyDFS(int curr){
	printf("\n");
	for (int next: graph[curr]){
		if (depth[next] == -1){
			parent[next] = curr;
			depth[next] = depth[curr] + 1;
			maketreebyDFS(next);
		}
	}
}

int main(){
	scanf("%d %d", &N, &M);
	fill(depth, depth+N, -1);
	depth[0] = 0; // **************
	for (int i=0;i<M;i++){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u-1].push_back(v-1);
		graph[v-1].push_back(u-1);
	}
	maketreebyDFS(0);
	printf("%d", depth[4]);
}