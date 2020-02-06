#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, n, w;
    scanf("%d %d %d %d", &a, &b, &n, &w);
    if (b==a && n*a == w && n == 2){
    	printf("1 1");
    }
    else if (b==a) {
    	printf("-1");
    }
    else {
    	if ((w-n*a)%(b-a) != 0){
    		printf("-1");
    		return 0;
    	}
    	int y = (w-n*a) / (b-a);
    	int x = n - y;
    	if(x<=0||x>=n||y<=0||y>=n){
    		printf("-1");
    	}
    	else {
    		printf("%d %d", x, y);
    	}
    }
}