#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N,M,T;
int a,b;
int main(){
   	scanf("%d",&T);
   	while(T--){
   		scanf("%d %d %d %d",&M,&N,&a,&b);
   		if(M==1){
   			printf("%d\n",b);
   			continue;
   		}
   		else if(N==1){
   			printf("%d\n",a);
   			continue;
   		}
   		//printf("%d %d %d %d",M,N,a,b);
   		int x=1,y=1;
   		int now=1;
   		bool check=false;
   		while(x!=M&&y!=N){
   			// printf("%d %d\n", x, y);
   			if (a-x == b-y && a-x >= 0) {
   				// printf("case a\n");
   				now += (a-x);
   				printf("%d\n", now);
   				check = true;
   				break;
   			}
   			if (M-x < N-y) {
   				// printf("case b\n");
   				y += M - x + 1;
   				now += M - x + 1;
   				x = 1;
   			}
   			else if (M-x > N-y){
   				// printf("case c\n");
   				x += N - y + 1;
   				now + N - y + 1;
   				y = 1;
   				
   			}
   			else {
   				// printf("case d\n");
   				now += M-x;
   				x = M;
   				y = N;
   			}
   		}
   		if (!check) {
   			if (a==M && b==N){
   				printf("%d\n", now);
   			}
   			else {
   				printf("-1\n");
   			}
   		}  		
   		

   	}
}