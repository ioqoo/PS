#include <bits/stdc++.h>

const int MAX = 500005;

using namespace std;

char S[MAX];
int N, d, SA[MAX], LCP[MAX], G[MAX]; // G == inverse of SA

bool cmp(int i, int j){ // sort by Group #
	if (G[i] != G[j]) return G[i] < G[j];
	i += d; j += d;
	return (i < N && j < N) ? (G[i] < G[j]) : (i > j);
}

void construct_SA(){
	N = strlen(S);
	for (int i=0;i<N;i++){
		SA[i] = i;
		G[i] = S[i];
	}
	
	for (d=1; ;d*=2){
		sort(SA, SA+N, cmp);
		
		int temp_G[MAX] = {0,};
		
		for (int i=0;i<N-1;i++){
			temp_G[i+1] = temp_G[i] + cmp(SA[i], SA[i+1]);
		}
		for (int i=0;i<N;i++){
			G[SA[i]] = temp_G[i];
		}
		
		if (temp_G[N-1] == N-1) break;
		// all suffix was separated into all other groups.
	}
}

void construct_LCP(){
	for (int i=0,k=0;i<N;i++, k=max(k-1, 0)){
		if (G[i] == N-1) continue; // last suffix ( <=> length == 1 )
		
		// i : curr, j : next
		for (int j=SA[G[i]+1];S[i+k]==S[j+k];k++);
		
		LCP[G[i]] = k;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%s", S);
	construct_SA();
	construct_LCP();
	
	for (int i=0;i<N;i++){
		printf("%d ", SA[i] + 1);
	}
	printf("\nx ");
	for (int i=0;i<N-1;i++){
		printf("%d ", LCP[i]);
	}
	
	
	return 0;
}


