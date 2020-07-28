#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
const int MAX = 100005;

using namespace std;

int N;

struct P{
	int x, y;
	bool operator < (const P &B) const {
		if (y == B.y) return x < B.x;
		return y < B.y;
	}
};

bool cmp_for_sort(const P &A, const P &B){
	return A.x < B.x;
}

int dist_sqrd(P A, P B){
	return (A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y); 
}

vector<P> co;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	scanf("%d", &N);
	for (int i=0;i<N;i++){
		int x, y;
		scanf("%d %d", &x, &y);
		co.push_back({x, y});
	}
	sort(all(co), cmp_for_sort);
	
	set<P> box = {co[0], co[1]};
	int ans = dist_sqrd(co[0], co[1]);
	int last_start = 0;
	for (int i=2;i<N;i++){
		P curr = co[i];
		while(last_start < i){
			P pre = co[last_start];
			int x_diff = abs(pre.x - curr.x);
			if (x_diff*x_diff > ans){
				box.erase(pre);
				last_start++;
			}
			else break;
		}
		auto lb = box.lower_bound({-1000000, curr.y - (int)sqrt(ans)});
		auto ub = box.upper_bound({1000000, curr.y + (int)sqrt(ans)});
		for (auto it=lb;it!=ub;it++){
			int curr_dist = dist_sqrd(curr, *it);
			if (curr_dist < ans) {
				ans = curr_dist;
			}
		}
		box.insert(curr);
	}
	printf("%d\n", ans);
	
	
	
	return 0;
}


