#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;
	scanf("%d", &N);
	if (N==1 || N==2){
		printf("0\n");
		return 0;
	}
	vector<int> arr(N);
	for (int i=0;i<N;i++){
		scanf("%d", &arr[i]);
	}
	bool asc = false;
	bool des = false;

	int cnt = 0;
	int pos = -1;
	for (int i=0;i<N-2;i++){
		if ((arr[i] <= arr[i+1]) ^ (arr[i+1] <= arr[i+2])){
			if (pos == -1) pos = i+1;
			cnt++;
		}
	}
//	printf("%d\n", cnt);
	if (cnt == 0){
		printf("0\n");
		return 0;
	}
	vector<int> arr2;
	for (int i=pos+1;i<N;i++){
		arr2.push_back(arr[i]);
	}
	for (int i=0;i<=pos;i++){
		arr2.push_back(arr[i]);
	}
	int cnt2 = 0;
	for (int i=0;i<N-2;i++){
		if ((arr2[i] < arr2[i+1]) ^ (arr2[i+1] < arr2[i+2])){
			cnt2++;
		}
	}
//	printf("%d\n", cnt2);
	if (cnt2 == 0) {
		printf("%d\n", pos+1);
		return 0;
	}
	else{
		arr2.clear();
		for (int i=1;i<N;i++){
			arr2.push_back(arr[i]);
		}
		arr2.push_back(arr[0]);
		int cnt3 = 0;
		for (int i=0;i<N-2;i++){
			if ((arr2[i] < arr2[i+1]) ^ (arr2[i+1] < arr2[i+2])){
				cnt3++;
			}
		}
		if (cnt3 == 0) printf("%d\n", 1);
		return 0;
	}
	printf("-1\n");
	
	
	return 0;
}


