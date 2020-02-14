#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int num[10];
int ans[10];
bool visited[10];

void DFS(int pos){
	if (pos == M){
		int before = -1;
		vector<int> ret;
		for (int i=0;i<M;i++){
			if (before <= ans[i]){
				ret.push_back(ans[i]);
				before = ans[i];
			}
			else{
				return;
			}
		}
		
		for (int n: ret){
			printf("%d ", n);
		}
		puts("");
	}
	
	int before = -1;
	for (int curr_pos = 0;curr_pos < N;curr_pos++){
		if (!visited[curr_pos] && (curr_pos == 0 || before != num[curr_pos])){
			before = num[curr_pos];
			ans[pos] = num[curr_pos];
			visited[curr_pos] = true;
			DFS(pos+1);
			visited[curr_pos] = false;
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d %d", &N, &M);
	
	for (int i=0;i<N;i++){
		scanf("%d", &num[i]);
	}
	
	sort(num, num+N);
	
	DFS(0);
	
	return 0;
}
