#include <iostream>
#include <cstdio>
//#include <string>
//#include <cstdlib> // atoi
//#include <cmath>
//#include <cstring> // memset, memcpy
//#include <algorithm>
//#include <stack>
#include <queue>
//#include <deque>
//#include <vector>
#include <functional>
//#include <map>
//#include <set>
//#include <utility> // pair
#define ll long long
//#define pii pair<int, int>

using namespace std;

int N;
vector<ll> graph[500000];
bool visited[500000];
ll answer;

bool is_leaf(int node){
	for (int i=0;i<graph[node].size();i++){
		if (visited[graph[node][i]] == false){
			return false;
		}
	}
	return true;
}


void dfs(ll node, ll level){
	visited[node] = true;
	if (is_leaf(node)) {
		answer += level;
		return;
	}
	for (int i=0;i<graph[node].size();i++){
		ll next = graph[node][i];
		if (!visited[next]) {
			dfs(next, level+1LL);
		}
	}
}
		

int main(){
	scanf("%d", &N);
	for (int i=0;i<N;i++){
		ll u, v;
		scanf("%lld %lld", &u, &v);
		graph[u-1].push_back(v-1);
		graph[v-1].push_back(u-1);
	}
	dfs(0LL, 0LL);
	if (answer%2) printf("Yes");
	else printf("No");
}