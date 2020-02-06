#include <iostream>
#include <cstdio>
#include <string>
//#include <cstring> // memset, memcpy
#include <algorithm>
//#include <stack>
//#include <queue>
//#include <deque>
//#include <vector>
//#include <functional>
//#include <map>
//#include <set>
//#include <utility> // pair
#define INF 100000000

using namespace std;

int N, M;
int dist[101][101];

int main(){
	scanf("%d %d", &N, &M);

	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			if (i!=j) dist[i][j] = INF;
		}
	}
	for (int X=0;X<M;X++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		dist[u-1][v-1] = min(dist[u-1][v-1], w);
	}

	for (int k=0;k<N;k++){
		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			if (dist[i][j] != INF)printf("%d ", dist[i][j]);
			else printf("0 ");
		}
		printf("\n");
	}	
}