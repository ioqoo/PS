#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long


using namespace std;

int N, M;
int num[10];
int ans[10];
bool visited[10];

void DFS(int pos){
	if (pos == M) {
		for (int i=0;i<M;i++){
			printf("%d ", ans[i]);
		}
		puts("");
		return;
	}
	
	int before = -1;
	for (int curr=0;curr<N;curr++){
		if (!visited[curr] && (curr == 0 || before != num[curr])){
			before = num[curr];
			ans[pos] = num[curr];
			visited[curr] = true;
			DFS(pos+1);
			visited[curr] = false;
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for (int i=0;i<N;i++){
		int temp;
		cin >> temp;
		num[i] = temp;
	}
	
	sort(num, num+N);
	
	
	DFS(0);
	
	
	return 0;
}
