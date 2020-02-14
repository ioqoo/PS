#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> ii;

vector<int> LIS(vector<int>& in){ // return LIS of array 'in'
	int n = in.size();
	vector<int> parent(n+1); // parent index
	vector<ii> is; //(number, index in 'in');
	is.push_back(ii(-99999999, -1));
	for(int i=0; i<n; ++i){
		if(is.back().first < in[i]){
			parent[i] = is.back().second;
			is.push_back(ii(in[i], i));
		} else{
			auto it = lower_bound(is.begin(), is.end(), ii(in[i], i));
			parent[i] = (it-1)->second;
			*it = ii(in[i], i);
		}
	}

	vector<int> ret;
	for(int i=is.back().second; i>=0; i=parent[i])
		ret.push_back(in[i]);
	reverse(ret.begin(), ret.end());
	return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
		
	int n; scanf("%d", &n);
	vector<int> arr(n);
	for(int i=0; i<n; ++i)
		scanf("%d", &arr[i]);

	vector<int> _lis = LIS(arr);
	printf("%d\n", _lis.size());
	for(auto i=_lis.begin(); i<_lis.end(); ++i)
		printf("%d ", *i);
}
