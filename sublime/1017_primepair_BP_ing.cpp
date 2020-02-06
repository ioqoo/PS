#include <bits/stdc++.h>


using namespace std;

bool prime[3000];
int A[55], B[55];
int even[55], odd[55];
vector<int> graph[55];
bool visited[55];

bool dfs(int a){
	visited[a] = true;
	for (int b:graph[a]){
		if (B[b] == 0 || !visited[B[b]] && dfs(B[b])){
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	prime[0] = prime[1] = true; // true : not prime
	for (int i=2;i<=1010;i++){
		if (!prime[i]){
			for (int j=2;i*j<=2010;j++){
				prime[i*j] = true;
			}
		}
	}

	int n;
	scanf("%d", &n);
	if (n%2) {
		printf("-1\n");
		return 0;
	}

	int left_i = 1, right_i = 1;
	for (int i=0;i<n;i++){
		int temp;
		scanf("%d", &temp);
		if (temp%2) { //even
			even[left_i] = temp;
			left_i++;
		}
		else{
			odd[right_i] = temp;
			right_i++;
		}
	}
	for (int i=1;i<=left_i;i++){
		for (int j=1;j<=right_i;j++){
			if (!prime[even[i]+odd[j]]){
				graph[i].push_back(j);
			}
		}
	}
	for (int i=0;i<graph[1].size();i++){
		int ans = 0;
		for (int i=1;i<=left_i;i++){
			if (A[i] == 0){
				fill(visited+1, visited+n+1, false);
				if (dfs(i)) ans++;;
			}
		}
		if (ans == n/2) printf("%d\n", odd[A[1]]);		
	}


}