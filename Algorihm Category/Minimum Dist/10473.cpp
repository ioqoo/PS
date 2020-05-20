#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>

#define ll long long
#define ld long double
#define MAX 111
#define INF 10000000000.0
#define pdd pair<ld, ld>
#define pid pair<int, ld>
#define pdi pair<ld, int>
#define pidd pair<int, pdd>
#define pddd pair<ld, pdd>
#define START 101
#define END 102

using namespace std;

pdd S, D;
int N;
pdd canons[MAX];
vector<pid> graph[MAX];
ld dist[MAX];
bool visited[MAX];


ld Euclid(pdd A, pdd B){
	ld x1 = A.first, y1 = A.second;
	ld x2 = B.first, y2 = B.second;
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

ld shoot_dist(pdd A, pdd B){
	ld d = Euclid(A, B);
	ld ret1 = 2.0 + abs(d-50.0)/5.0;
	ld ret2 = d/5.0;
	return min(ret1, ret2);
}

ld walk_dist(pdd A, pdd B){
	ld d = Euclid(A, B);
	return d/5.0;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);

	ld x, y;
	scanf("%Lf %Lf", &x, &y);
	S = pdd(x, y);
	scanf("%Lf %Lf", &x, &y);
	D = pdd(x, y);
	scanf("%d", &N);
	for (int i=0;i<N;i++){
		scanf("%Lf %Lf", &x, &y);
		canons[i] = pdd(x, y);
	}
	
	for (int u=0;u<N-1;u++){
		for (int v=u+1;v<N;v++){
			pdd A = canons[u], B = canons[v];
			graph[u].push_back(pid(v, shoot_dist(A, B)));
			graph[v].push_back(pid(u, shoot_dist(A, B)));
		}
	}
	
	for (int u=0;u<N;u++){
		pdd A = canons[u];
		graph[START].push_back(pid(u, walk_dist(S, A)));
		graph[u].push_back(pid(END, shoot_dist(A, D)));
	}
	graph[START].push_back(pid(END, walk_dist(S, D)));
	
	priority_queue<pdi, vector<pdi>, greater<pdi>> PQ;
	for (int i=0;i<MAX;i++){
		dist[i] = INF;
	}
	dist[START] = 0;
	visited[START] = true;
	PQ.push(pdi(0., START));
	while(!PQ.empty()){
		pdi p = PQ.top();
		PQ.pop();
		ld curr_dist = p.first;
		int curr = p.second;
		for (auto pp: graph[curr]){
			int next = pp.first;
			ld weight = pp.second;
//			if (visited[next]) continue;
			if (dist[next] > curr_dist + weight){
				dist[next] = curr_dist + weight;
				visited[next] = true;
				PQ.push(pdi(dist[next], next));
			}
		}
	}
	
	printf("%Lf\n", dist[END]);

    return 0;

}
