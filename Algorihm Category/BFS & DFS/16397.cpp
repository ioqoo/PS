#include <bits/stdc++.h>
#define LIMIT 100000
using namespace std;

int A(int n){
	int ret = n+1;
	if (ret >= LIMIT) return -1;
	return ret;
}

int B(int n){
	int ret = 2*n;
	if (ret >= LIMIT) return -1;
	int pos = (int)floor(log10(ret));
	ret -= (int)pow(10, pos);
	return ret;
}

int dist[LIMIT+5];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    int N, T, G;
    scanf("%d %d %d", &N, &T, &G);
    memset(dist, -1, sizeof(dist));
    
    queue<int> Q;
    Q.push(N);
    dist[N] = 0;
    bool succ = false;
    while(!Q.empty()){
    	int curr = Q.front(); Q.pop();
//    	printf("%d\n", curr);
    	if (curr == G) {
    		succ = true;
    		break;
		}
		if (dist[curr] == T) continue;
    	int na = A(curr), nb = B(curr);
//    	printf("%d %d\n", na, nb);
    	if (na != -1){
    		if (dist[na] == -1){
	    		dist[na] = dist[curr] + 1;
	    		Q.push(na);
			}
		}
		if (nb != -1){
			if (dist[nb] == -1){
				dist[nb] = dist[curr] + 1;
				Q.push(nb);
			}
		}
	}
	
	if (succ) printf("%d\n", dist[G]);
	else printf("ANG\n");
    
    
    

    return 0;
}



