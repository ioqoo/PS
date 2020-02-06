#include <bits/stdc++.h>

using namespace std;

int val[5555];
int kval[5555][5];
set<int> dp[5055][5];
int main(){
    int w,n;
    scanf("%d %d",&w,&n);
    for(int i=0;i<n;i++){
    	scanf("%d",&val[i]);
    }
    sort(val,val+n);
    for(int i=4;i<n;i++){
    	kval[i][0]=val[i]-val[0];
    	kval[i][1]=val[i]-val[1];
    	kval[i][2]=val[i]-val[2];
    	kval[i][3]=val[i]-val[3];
    }
    if(w<val[0]+val[1]+val[2]+val[3]) {
    	printf("NO");
    	return 0;
    }
    else if(w==val[0]+val[1]+val[2]+val[3]){
    	printf("YES");
    	return 0;
    }
    w-=(val[0]+val[1]+val[2]+val[3]);
    for(int i=4;i<n;i++){
    	for(int j=0;j<=3;j++){
  			if(kval[i][j]==w){
  				printf("YES");
  				return 0;
  			}
  			if(kval[i][j]>w) continue;
    		for(int p: dp[i][j]){	    			
    			// printf("%d %d %d %d %d\n",i,j,p,p+kval[i][j],w);
    			if(p+kval[i][j]==w){
	   				printf("YES");
	  				return 0;   				
    			}

    			dp[i][j+1].insert(p);
    			dp[i+1][j].insert(p);
    			if(kval[i][j]+p<w) dp[i+1][j+1].insert(kval[i][j]+p);
    		}
	    	dp[i+1][j+1].insert(kval[i][j]);
    	}
    }
    printf("NO");
}