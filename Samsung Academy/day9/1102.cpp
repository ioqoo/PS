#include <iostream>
#include <cstring>
#include <string>

#define INF 987654321

using namespace std;

int N, P;
int W[16][16];
int dp[1<<16];
int init;

int check_ones(int n){
	int ret = 0;
	for (int i=0;i<16;i++){
		if (n & ((1<<i))) ret++;
	}
	
	return ret;
}

int travel(int stat){
	int &ret = dp[stat];
	if (ret != -1) return ret;

	if (check_ones(stat) >= P) return 0;
	
	ret = INF;
	
	// u -> v
	for (int v=0;v<N;v++){
		if (stat & (1 << v)) continue; // 도착점이 켜져있으면 continue 
		int curr_min = INF;
		for (int u=0;u<N;u++){
			if (!(stat & (1 << u))) continue; // 출발점이 꺼져 있으면 continue 
//			cout << "u : " << u+1 << "/ v: " << v+1 << endl;
			curr_min = min(curr_min, W[u][v]); 
		}
		ret = min(ret, travel( stat | (1<<v) ) + curr_min);
	}
//	cout << endl;
	return ret;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			int temp;
			cin >> temp;
			W[i][j] = temp;
		}
	}
	string str;
	cin >> str;
	
	int curr_avail = 0;
	for (int i=0;i<str.size();i++){
		if (str[i] == 'Y'){
			init += (1 << i);
			curr_avail++;
		}
	}
	cin >> P;
	
    if (check_ones(init) >= P){
        printf("0\n");
        return 0;
    }
    
    if (check_ones(init) == 0){
        printf("-1\n");
        return 0;
    }
    
    
	
	memset(dp, -1, sizeof(dp));
	
	cout << travel(init);
	
	
	return 0;
}
