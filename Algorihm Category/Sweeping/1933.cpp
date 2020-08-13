#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

using namespace std;

struct edge{
	int x, y;
	bool is_start;
	
	bool operator < (edge B){
		if (x == B.x) return is_start < B.is_start;
		return x < B.x;
	}
};

vector<edge> E;

multiset<int, greater<int>> S;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;
	
	scanf("%d", &N);
	for (int i=0;i<N;i++){
		int l, h, r;
		scanf("%d %d %d", &l, &h, &r);
		E.push_back({l, h, true});
		E.push_back({r, h, false});
	}
	
	sort(all(E));
	
	map<int, int> mp;
	
	for (int i=0;i<2*N;i++){
		auto curr = E[i];
		if (S.empty()){
			mp[curr.x] = max(mp[curr.x], curr.y);
			S.insert(curr.y);
//			printf("%d\n", *(S.begin()));
			continue;
		}
		if (curr.is_start){
			auto it = S.begin();
			int top = *it;
			if (curr.y > top){
				if (!mp.count(curr.x)) mp[curr.x] = curr.y;
				mp[curr.x] = max(mp[curr.x], curr.y);
			}
			S.insert(curr.y);
		}
		else{
			S.erase(S.find(curr.y));
			if (S.empty()) {
				mp[curr.x] = 0;
				continue;
			}
			auto it = S.begin();
			int top = *it;
			if (top < curr.y){
				if (!mp.count(curr.x)) mp[curr.x] = top;
				else mp[curr.x] = min(mp[curr.x], top);
			}
		}
//		printf("%d\n", *(S.begin()));
	}
	
//	for (auto p: ans){
//		if (mp.count(p.first)) continue;
//		mp[p.first] = p.second;
//	}
	
	int prev = -1;
	for (auto it = mp.begin();it!=mp.end();it++){
		if (it->first == prev) continue;
		printf("%d %d ", it->first, it->second);
		prev = it->first;
	}
	
	return 0;
}


