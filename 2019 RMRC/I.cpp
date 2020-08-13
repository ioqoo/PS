#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N, P, D;
	cin >> N >> P >> D;
	
	string arr;
	cin >> arr;
	
	for (int i=0;i<P;i++){
		arr += arr[i];
	}
	
	int sleepcnt = 0;
	int tiredcnt = 0;
	queue<bool> Q; // W : false, Z : true
	for (int i=0;i<P;i++){
		char curr = arr[i];
		if (curr == 'W'){
			Q.push(false);
		}
		else if (curr == 'Z'){
			Q.push(true);
			sleepcnt++;
		}
	}
	if (sleepcnt < D) tiredcnt++;
	for (int i=P;i<N+P-1;i++){
//		printf("slcnt : %d\n", sleepcnt);
		if (Q.front() == true){
			sleepcnt--;
		}
		Q.pop();
		char curr = arr[i];
		if (curr == 'W'){
			Q.push(false);
		}
		else if (curr == 'Z'){
			Q.push(true);
			sleepcnt++;
		}
		if (sleepcnt < D) tiredcnt++;
	}
	printf("%d\n", tiredcnt);
	
	
	
	return 0;
}

