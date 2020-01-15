// https://www.acmicpc.net/problem/18228

#include <bits/stdc++.h>
#define ll long long
#define MAX 1234567890

using namespace std;

int N;
int A[200005];
int K;
int l_min = MAX;
int r_min = MAX;


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

	scanf("%d", &N);
	for (int i=0;i<N;++i){
		scanf("%d", &A[i]);
		if (A[i] == -1) K = i;
	}
	for (int i=0;i<K;++i){
		l_min = min(l_min, A[i]);
	}
	for (int i=N-1;i>K;--i){
		r_min = min(r_min, A[i]);
	}
	printf("%d\n", l_min + r_min);
	return 0;
}
