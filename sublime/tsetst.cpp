#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;


struct Point{
	int midx;
	int midy;
	int len;
	int x1;
	int x2;
};
typedef struct Point point;

int inner(point a, point b){
	return (a.x1*b.x1+a.x2*b.x2);
}

bool cmp(point a, point b){
	if(a.midx!=b.midx) return a.midx<b.midx;
	else if(a.midy!=b.midy) return a.midy<b.midy;
	else if(a.len!=b.len) return a.len<b.len;
	else {
		if(a.y>=0&&b.y>=0){
			return a.x>b.x;
		}
		else if(a.y*b.y<0){
			return a.y>b.y;
		}
		else {
			return a.x<b.x;
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N;
		scanf("%d",&N);
		vector <pii> vv;
		for(int i=0;i<N;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			vv.push_back(pii(a,b));
		}
		vector <point> pp;
		for(int i=0;i<N;i++){
			for(int j=i+1;j<N;j++){
				point k;
				k.midx=vv[i].first+vv[j].first;
				k.midy=vv[i].second+vv[j].second;
				k.len=(vv[i].first-vv[j].first)*(vv[i].first-vv[j].first)+(vv[i].second-vv[j].second)*(vv[i].second-vv[j].second);
				k.x1=vv[i].first-vv[j].first;
				k.x2=vv[i].second-vv[j].second;
				pp.push_back(k);
			}
		}
		sort(pp.begin(),pp.end(),cmp);
		bool visited[9000002];
		memset(visited,0,sizeof(visited));
		int sze=pp.size();
		int ans=0;
		for(int i=0;i<sze;i++){
			if(visited[i]) continue;
			for(int j=i+1;j<sze;j++){
				if(visited[j]) break;
				if(pp[i].midx!=pp[j].midx) break;
				else if(pp[i].midy!=pp[j].midy) break;
				else if(pp[i].len!=pp[j].len) break;
				else{
					if(inner(pp[i],pp[j])==0) {
						//printf("1");
						ans=max(ans,pp[i].len/2);
						visited[i]=visited[j]=true;
						break;
					}
				}

			}
		}
		printf("%d\n",ans);
	}
}