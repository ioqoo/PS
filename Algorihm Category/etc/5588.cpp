#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

//struct co{
//	int x, y;
//	bool operator < (co B){
//		return x < B.x;
//	}
//};
//
//struct diff{
//	int dx, dy;
//	bool operator < (diff B){
//		return dx < B.dx;
//	}
//};

int M, N;
vector<pii> star;
set<pii> D;
set<pii> pic;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d", &M);
	for (int i=0;i<M;i++){
		int x, y;
		scanf("%d %d", &x, &y);
		star.push_back({x, y});
	}
	
	scanf("%d", &N);
	for (int i=0;i<N;i++){
		int x, y;
		scanf("%d %d", &x, &y);
		pic.insert({x, y});
	}
	
	for (int i=0;i<M;i++){
		auto from = star[i];
		for (auto to: pic){
			D.insert({to.first - from.first, to.second - from.second});
		}
	}
	
	for (auto d: D){
		bool succ = true;
		for (auto c: star){
			if (!pic.count({c.first + d.first, c.second + d.second})){
				succ = false;
				break;
			}
		}
		if (succ){
			printf("%d %d\n", d.first, d.second);
			return 0;
		}
	}
	
	
	return 0;
}


