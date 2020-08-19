#include <bits/stdc++.h>
#define ll long long
const int NMAX = 100005;
const int MAX = 1 << (int)(ceil(log2(NMAX)+1));
using namespace std;

int N, leaf_size;
int tree[MAX];

void update(int pos, int diff){
	pos += leaf_size;
	tree[pos] += diff;
	while(pos > 1){
		pos /= 2;
		tree[pos] = tree[pos*2] + tree[pos*2+1];
	}
}

int sum(int node, int l, int r, int s, int e){
	if (r < s || e < l) return 0;
	if (s <= l && r <= e) return tree[node];
	int mid = (l+r) / 2;
	return sum(node*2, l, mid, s, e) + sum(node*2+1, mid+1, r, s, e);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	vector<string> L;
	map<string, int> R;
	
	cin >> N;
	leaf_size = 1 << (int)ceil(log2(N));
	for (int i=0;i<N;i++){
		string word;
		cin >> word;
		L.push_back(word);
	}
	
	sort(L.begin(), L.end());
	
	for (int i=0;i<N;i++){
		string temp = L[i];
		reverse(temp.begin(), temp.end());
		R[temp] = i;
	}
	ll ans = 0;
	for (auto it = R.begin();it!=R.end();it++){
		string word = it->first;
		int num = it->second;
		ans += (ll)sum(1, 0, leaf_size-1, num+1, N-1);
		update(num, 1);
	}
	printf("%lld\n", ans);
	
	
	
	
	
	return 0;
}

