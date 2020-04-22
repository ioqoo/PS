#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>

#define pii pair<int, int>
#define MAX 1005
#define INF 0x3f3f3f3f

using namespace std;

int T;
int R, C;
string row;
int grid[MAX][MAX];
int dist[MAX];
bool visited[MAX];
priority_queue<pii, vector<pii>, greater<pii>> PQ1;
priority_queue<pii, vector<pii>, greater<pii>> PQ2;
vector<int> graph[MAX*MAX];
int node_num = 1;
int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
    cin >> T;
    cout << T;

	return 0;
}

