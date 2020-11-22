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
	
	int max_pos, max_val=0, min_pos, min_val = 2e9;
	for (int i=0;i<N;i++){
		int curr = arr[i];
		if (curr > max_val) {
			max_val = curr;
			max_pos = i;
		}
		if (curr < min_val){
			min_val = curr;
			min_pos = i;
		}
	}
//	min_pos++;
//	max_pos++;
	
	bool asc = false;
	bool des = false;
	bool succ = true;
	for (int i=0;i<N-1;i++){
		if (arr[i] == arr[i+1]) continue;
		else if (arr[i] < arr[i+1]){
			if (des){
				succ = false;
				break;
			}
			asc = true;
		}
		else if (arr[i] > arr[i+1]){
			if (asc){
				succ = false;
				break;
			}
			des = true;
		}
	}
	if (succ){
		printf("0\n");
		return 0;
	}
	
	vector<int> A;
	for (int i=min_pos;i<N;i++){
		A.push_back(arr[i]);
	}
	for (int i=0;i<min_pos;i++){
		A.push_back(arr[i]);
	}
//	for (int n: A){
//		printf("%d ", n);
//	}
//	printf("\n");	
	bool succ_min = true;
	asc = false;
	des = false;
	for (int i=0;i<N-1;i++){
		if (A[i] == A[i+1]) continue;
		else if (A[i] < A[i+1]){
			if (des) {
				succ_min = false;
				break;
			}
			asc = true;
		}
		else if (A[i] > A[i+1]){
			if (asc){
				succ_min = false;
				break;
			}
			des = true;
		}
	}
//	printf("%d\n", max_pos);
	
	vector<int> B;
	for (int i=max_pos;i<N;i++){
		B.push_back(arr[i]);
	}
	for (int i=0;i<max_pos;i++){
		B.push_back(arr[i]);
	}

	bool succ_max = true;
	asc = false;
	des = false;
	for (int i=0;i<N-1;i++){
		if (B[i] == B[i+1]) continue;
		else if (B[i] < B[i+1]){
			if (des) {
				succ_max = false;
				break;
			}
			asc = true;
		}
		else if (B[i] > B[i+1]){
			if (asc){
				succ_max = false;
				break;
			}
			des = true;
		}
	}
	if (succ_min && succ_max){
		printf("%d\n", min(min_pos, max_pos));
	}
	else if (succ_min){
		printf("%d\n", min_pos);
	}
	else if (succ_max){
		printf("%d\n", max_pos);
	}
	else printf("-1\n");
	
	
	return 0;
}


