#include <bits/stdc++.h>
#define pii pair<int,int>
#define MAX 987654321
using namespace std;

int turn_fuel[103][103][250][2];
// i, j, k, l : (i,j)까지 k번 꺾고 올 수 있는 연료의 최소값, l은 (i,j)로 들어온 게 hori인지 vert인지(0 : vert, 1 : hori);
int hori_fuel[103][103]; // (i,j) : (i,j-1) ~ (i,j)로 가는 연료
int vert_fuel[103][103]; // (i,j) : (i-1,j) ~ (i,j)로 가는 연료

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int ans = 0;
		memset(hori_fuel, 0, sizeof(hori_fuel));
		memset(vert_fuel, 0, sizeof(vert_fuel));
		int m, n, l, g;
		scanf("%d %d %d %d", &m, &n, &l, &g);
		for (int i=0;i<=102;i++){
			for (int j=0;j<=102;j++){
				for (int k=0;k<=249;k++){
					turn_fuel[i][j][k][0] = MAX;
					turn_fuel[i][j][k][1] = MAX;
				}
			}
		}

		for (int i=0;i<m;i++){ // hori
			for (int j=0;j<n-1;j++){
				int fuel;
				scanf("%d", &fuel);
				hori_fuel[i][j+1] = fuel;
				// printf("%d ", hori_fuel[i][j]);
			}
			// printf("\n");
		}
		for (int i=0;i<m-1;i++){ // vert
			for (int j=0;j<n;j++){
				int fuel;
				scanf("%d", &fuel);
				vert_fuel[i+1][j] = fuel;
			}
		}
		for (int i=0;i<=m;i++){
			for (int j=0;j<=n;j++){
				for (int k=0;k<=200;k++){
					if (i==0 && j==0){
						turn_fuel[i][j][k][0] = 0;
						turn_fuel[i][j][k][1] = 0;
					}
					else if (i==0){
						turn_fuel[i][j][0][0] = turn_fuel[i][j-1][0][0] + hori_fuel[i][j];
					}
					else if (j==0){
						turn_fuel[i][j][0][1] = turn_fuel[i-1][j][0][1] + vert_fuel[i][j];
					}
					else {
						turn_fuel[i][j][k][0] = min(turn_fuel[i][j-1][k-1][1], turn_fuel[i][j-1][k][0]) + hori_fuel[i][j];
						turn_fuel[i][j][k][1] = min(turn_fuel[i-1][j][k-1][0], turn_fuel[i-1][j][k][1]) + vert_fuel[i][j];
					}
				}	
			}		
		}
		bool check = false;
		for (int k=1;k<=200;k++){
			int a, b;
			// printf("%d %d\n", turn_fuel[m-1][n-1][k][0], turn_fuel[m-1][n-1][k][1]);
			if (turn_fuel[m-1][n-1][k][0] <= g){
				a = turn_fuel[m-1][n-1][k][0];
			}
			else {
				a = MAX;
			}
			if (turn_fuel[m-1][n-1][k][1] <= g){
				b = turn_fuel[m-1][n-1][k][0];
			}
			else {
				b = MAX;
			}
			if (a!=MAX || b!=MAX){
				printf("%d\n", (m+n-2)*l + k);
				check = true;
				break;
			}
		}
		if (!check){
			printf("-1\n");
		}
	}
}