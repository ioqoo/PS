#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

bool ccw(pair<pii,pii> a, pair<pii,pii> b){
	ll v1=(a.second.first-a.first.first)*(b.second.second-a.first.second)-(a.second.second-a.first.second)*(b.second.first-a.first.first);
	ll v2=(a.second.first-a.first.first)*(b.first.second-a.first.second)-(a.second.second-a.first.second)*(b.first.first-a.first.first);
	ll h1=(b.second.first-b.first.first)*(a.second.second-b.first.second)-(b.second.second-b.first.second)*(a.second.first-b.first.first);
	ll h2=(b.second.first-b.first.first)*(a.first.second-b.first.second)-(b.second.second-b.first.second)*(a.first.first-b.first.first);
	if(v1*v2>=0||h1*h2>=0) return true;
	else return false;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		priority_queue<pii, vector<pii>, greater<pii>> x_first;
		priority_queue<pii, vector<pii>, greater<pii>> y_first;
		map<int, int> x_cor;
		map<int, int> y_cor;
		int n;
		scanf("%d", &n);
		while(n--){
			int x, y;
			scanf("%d %d", &x, &y);
			x_cor[x]++;
			y_cor[y]++;
			x_first.push(pii(x,y));
			y_first.push(pii(y,x));
		}
		bool check=true;
		for(auto &p: x_cor){
			if(p.second%2==1) {
				check=false;
				break;
			}
		}
		for(auto &p: y_cor){
			if(p.second%2==1) {
				check=false;
				break;
			}
		}
		if (!check){
			printf("1");
			printf("NO\n");
			continue;
		}
		else{
			vector<pair<pii, pii>> y_dir_edges;
			vector<pair<pii, pii>> x_dir_edges;
			while(!x_first.empty()){
				pii first_v = x_first.top();
				x_first.pop();
				pii second_v = x_first.top();
				x_first.pop();
				y_dir_edges.push_back(make_pair(first_v, second_v));
			}
			while(!y_first.empty()){
				pii first_v = y_first.top();
				y_first.pop();
				pii second_v = x_first.top();
				y_first.pop();
				x_dir_edges.push_back(make_pair(first_v, second_v));
			}

			// x_dir_edges : x축이랑 평행한 edges들 vector
			// y_dir_edges : y축이랑 평행한 edges들 vector
			int aa=x_dir_edges.size();
			int bb=y_dir_edges.size();
			int dsad=true;
			for(int i=0;i<aa;i++){
				for(int j=0;j<bb;j++){
					if(ccw(x_dir_edges[i],y_dir_edges[j])) continue;
					else {
						dsad=false;
						
					}
				}
			}
			if(!dsad) printf("NO\n");
			else printf("YES\n");

		}
		
	}
}