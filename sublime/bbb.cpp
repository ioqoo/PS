#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;
vector <pii> vv;
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		vv.push_back(pii(b,a));
	}
	sort(vv.begin(),vv.end());
	int t=M;
	for(int i=t-2;i>=0;i-=2){
		if(vv[i].first==N&&vv[i+1].first==N){
			N--;
			M-=2;
		}
		else break;
	}
	//printf("%d",M);
	for(int i=1;i<M;i++){
		if(vv[i].first==vv[i-1].first&&vv[i].second!=vv[i-1].second){
			printf("No");
			return 0;
		}
		if(vv[i].first-vv[i-1].first==1&&vv[i].second!=vv[i-1].second){
			printf("No");
			return 0;
		}
	}
	int now=2;
	int nowval=1;
	for(int i=0;i<M;i++){
		if(vv[i].first==1&&vv[i].second==2) {
			now=1;
			continue;
		}
		if(vv[i].second==now){
			if((vv[i].first-nowval)%2==0){
				if(vv[i].second==1) now=2;
				else now=1;
				nowval=vv[i].first;
			}
			else {
				printf("No");
				return 0;
			}
		}
		else {
			if((vv[i].first-nowval)%2==1){
				if(vv[i].second==1) now=2;
				else now=1;
				nowval=vv[i].first;				
			}
			else {
				printf("No");
				return 0;
			}
		}
	}
	printf("Yes");

	
}