#include <iostream>
#include <string>

using namespace std;

bool is_selfnum[10005];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	fill(is_selfnum, is_selfnum+10005, true);
	for (int i=1;i<=10000;i++){
		int st = i;
		int temp = st;
		while(1){
			int sum = temp;
			string curr = to_string(temp);
			for (auto c: curr){
				sum += (c - '0');
			}
			if (sum == st) {
				break;
			}
			if (sum > 10000) break;
			is_selfnum[sum] = false;
			temp = sum;
		}
	}
	for (int i=1;i<=10000;i++){
		if (is_selfnum[i]) printf("%d\n", i);
	}
	
	
	return 0;
}


