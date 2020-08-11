#include <bits/stdc++.h>

using namespace std;

struct edge{
	int s, e;
	
	bool operator < (edge B){
		return s < B.s;
	}
};

struct cmp{
	bool operator () (edge A, edge B){
		return A.e > B.e;
	}
};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;
	scanf("%d", &N);
	vector<edge> H, V;
	int a, b;
	scanf("%d %d", &a, &b);
	int init_a = a, init_b = b;
	for (int i=0;i<N-1;i++){
		int x, y;
		scanf("%d %d", &x, &y);
		if (a == x){
			V.push_back({min(b, y), max(b, y)});
		}
		else if (b == y){
			H.push_back({min(a, x), max(a, x)});
		}
		a = x; b = y;
	}
	if (init_a == a){
		V.push_back({min(init_b, b) , max(init_b, b)});
	}
	else if (init_b == b){
		H.push_back({min(init_a, a), max(init_a, a)});
	}
	
	sort(H.begin(), H.end());
	sort(V.begin(), V.end());
	
	priority_queue<edge, vector<edge>, cmp> PQ1;
	int ans = 0;
	int curr = 0;
	for (auto E: H){
		while(!PQ1.empty() && PQ1.top().e <= E.s){
			PQ1.pop();
			curr--;
		}
		curr++;
		ans = max(ans, curr);
		PQ1.push(E);
//		printf("%d %d\n", PQ1.top().s, PQ1.top().e);
	}
	
	priority_queue<edge, vector<edge>, cmp> PQ2;
	int ans2 = 0;
	int curr2 = 0;
	for (auto E: V){
		while(!PQ2.empty() && PQ2.top().e <= E.s){
			PQ2.pop();
			curr2--;
		}
		curr2++;
		ans2 = max(ans2, curr2);
		PQ2.push(E);
//		printf("%d %d\n", PQ2.top().s, PQ2.top().e);
	}
	printf("%d\n", max(ans, ans2));
	
	
	
	
	return 0;
}


