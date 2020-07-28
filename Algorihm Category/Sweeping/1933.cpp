#include <bits/stdc++.h>
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

map<int, int> xmap;
map<int, int> hmap;

struct edge{
	int x, height;
	bool is_start;
	edge(int a, int b, bool c){
		x = a;
		height = b;
		is_start = c;
	}
	
	bool operator < (edge& b){
		if (x == b.x) return is_start > b.is_start;
		return x < b.x;
	}
};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;
	scanf("%d", &N);
	vector<edge> E;
	vector<int> hlist;
	for (int i=0;i<N;i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		hlist.push_back(b);
		E.push_back({a, b, true});
		E.push_back({c, b, false});
	}
	
	sort(all(hlist), greater<int>());
	hlist.erase(unique(all(hlist)), hlist.end());
	
	for (int i=0;i<hlist.size();i++){
		hmap[hlist[i]] = i;
	}
	
	vector<int> stat(N);
	
	sort(all(E));
	
	for (int i=0;i<
	
	
	
	
	return 0;
}


