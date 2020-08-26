#include <bits/stdc++.h>

using namespace std;

int grid[55][55];
int psum[55][55];
int N;

vector<int> sum_tl(int si, int sj){
	vector<int> ret;
	
	for (int i=si;i>0;i--){
		for (int j=sj;j>0;j--){
//			if (i == si && j == sj) continue;
			ret.push_back(psum[si][sj] - psum[i-1][sj] - psum[si][j-1] + psum[i-1][j-1]);
		}
	}
	return ret;
}

vector<int> sum_br(int si, int sj){
	vector<int> ret;
	
	for (int i=si+1;i<=N;i++){
		for (int j=sj+1;j<=N;j++){
//			if (i == si+1 && j == sj+1) continue;
			ret.push_back(psum[i][j] - psum[si][j] - psum[i][sj] + psum[si][sj]);
		}
	}
	return ret;
}

vector<int> sum_tr(int si, int sj){
	vector<int> ret;

	for (int i=si;i>0;i--){
		for (int j=sj+1;j<=N;j++){
//			if (i == si && j == sj+1) continue;
			ret.push_back(psum[si][j] - psum[si][sj] - psum[i-1][j] + psum[i-1][sj]);
		}
	}
	return ret;
}

vector<int> sum_bl(int si, int sj){
	vector<int> ret;
	
	for (int i=si+1;i<=N;i++){
		for (int j=sj;j>0;j--){
//			if (i == si+1 && j == sj) continue;
			ret.push_back(psum[i][sj] - psum[i][j-1] - psum[si][sj] + psum[si][j-1]);
		}
	}
	return ret;
}
	

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d", &N);
	for (int i=1;i<=N;i++){
		for (int j=1;j<=N;j++){
			scanf("%d", &grid[i][j]);
		}
	}
	
	for (int i=1;i<=N;i++){
		for (int j=1;j<=N;j++){
			psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + grid[i][j];
		}
	}
	int cnt = 0;
	for (int i=1;i<=N-1;i++){
		for (int j=1;j<=N-1;j++){
			vector<int> tl = sum_tl(i, j);
			vector<int> br = sum_br(i, j);
//			printf("%d %d\n", i, j);
//			printf("top left\n");
//			for (int a: tl){
//				printf("%d ", a);
//			}
//			printf("\n");
//			printf("bottom right\n");
//			for (int b: br){
//				printf("%d ", b);
//			}
//			printf("\n");
			for (int a: tl){
				for (int b: br){
					if (a == b){
						cnt++;
					}
				}
			}
			vector<int> tr = sum_tr(i, j);
			vector<int> bl = sum_bl(i, j);
//			printf("top right\n");
//			for (int a: tr){
//				printf("%d ", a);
//			}
//			printf("\n");
//			printf("bottom left\n");
//			for (int b: bl){
//				printf("%d ", b);
//			}
//			printf("\n");
			for(int a: tr){
				for (int b: bl){
					if (a == b){
						cnt++;
					}
				}
			}
		}
	}
	printf("%d\n", cnt);
	
	
	
	
	return 0;
}


