#include <bits/stdc++.h>

const int MAX = 105;
const int INF = 987654321;

using namespace std;
mp<string, int> mp;
vector<string> trav_list;
int grid[MAX][MAX];

struct traffic{
	string type, city_s, city_e;
	int cost;
};

vector<traffic> traf_list;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N, R;
	cin >> N >> R;
	int piv = 0;
	for (int i=0;i<N;i++){
		string temp;
		cin >> temp;
		mp[temp] = piv++;
	}
	int M;
	cin >> M;
	for (int i=0;i<M;i++){
		string temp;
		cin >> temp;
		trav_list.push_back(temp);
	}
	for (int i=0;i<MAX;i++){
		for (int j=0;j<MAX;j++){
			if (i==j) continue;
			grid[i][j] = INF;
		}
	}	
	
	int K;
	cin >> K;
	for (int i=0;i<K;i++){
		string t, c_s, c_e;
		int cost;
		cin >> t >> c_s >> c_e >> cost;
		traf_list.push_back({t, c_s, c_e, cost});
		grid[mp[c_s]][mp[c_e]] = grid[mp[c_e]][mp[c_s]] = cost;
	}
	
	for (int k=0;k<N;k++){
		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++){
				if (grid[i][j] > grid[i][k] + grid[k][j]){
					grid[i][j] = grid[i][k] + grid[k][j];
				}
			}
		}
	}
	
	
	
	
	
	return 0;
}


