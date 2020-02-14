#include <iostream>
#include <map>
#include <algorithm>

#define MAX 500005


using namespace std;

int N;
int arr[MAX];
int des_arr[MAX];
int ftree[MAX];
map<int, int> mp;

int Li(int x){
	return x&(-x);
}

int get_sum(int x){
	int ret = 0;
	while(x>0){
		ret += ftree[x];
		x -= Li(x);
	}
	return ret;
}

void update(int x, int diff){
	while(x<MAX){
		ftree[x] += diff;
		x += Li(x);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d", &N);
	for (int i=1;i<=N;i++){
		scanf("%d", &arr[i]);
		des_arr[i] = arr[i];
	}
	
	sort(des_arr+1, des_arr+N+1, greater<int>());
	
	for (int i=1;i<=N;i++){
		mp[des_arr[i]] = i;
	}
	
	for (int i=1;i<=N;i++){
		int curr_val = arr[i];
		int sorted_pos = mp[curr_val];
		printf("%d\n", i - (get_sum(N) - get_sum(sorted_pos)));
		update(sorted_pos, 1);
	}
	
	
	
	
	
	
	
	return 0;
}
