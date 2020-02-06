#include <bits/stdc++.h>
#define pii pair<int, int>
#define INF 1987654320

using namespace std;


int dist1[20022];
int dist2[20022];
int dist3[20022];
bool visited1[20022];
bool visited2[20022];
bool visited3[20022];
vector<pii> graph[20022];

int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE

   int n, m;
   scanf("%d %d", &n, &m);
   for (int i=0;i<m;i++){
	   int u, v, w;
	   scanf("%d %d %d", &u, &v, &w);
	   graph[u].push_back(pii(v, w));
	   graph[v].push_back(pii(u, w));
   }
   int v_1, v_2, v_3;
   scanf("%d %d %d", &v_1, &v_2, &v_3);

   fill(dist1, dist1+20022, INF);
   fill(dist2, dist2+20022, INF);
   fill(dist3, dist3+20022, INF);

   priority_queue<pii, vector<pii>, greater<pii>> PQ;
   PQ.push(pii(0,v_1));
   dist1[v_1] = 0;
   while (!PQ.empty()){
   		int curr;
   		do{
   			curr = PQ.top().second;
   			PQ.pop();
   		}while(!PQ.empty() && visited1[curr]);
   		if(visited1[curr]) break;

   		visited1[curr] = true;
   		int graph_size = graph[curr].size();
   		for (int i=0;i<graph_size;i++){
   			int next = graph[curr][i].first;
   			int d = graph[curr][i].second;
   			if (dist1[next] > dist1[curr]+d){
   				dist1[next] = dist1[curr] + d;
   				PQ.push(pii(dist1[next], next));
   			}
   		}
   }

   while(!PQ.empty()){
   	PQ.pop();
   }
   memset(visited1, 0, sizeof(visited1));

   PQ.push(pii(0,v_2));
   dist2[v_2] = 0;
   while (!PQ.empty()){
   		int curr;
   		do{
   			curr = PQ.top().second;
   			PQ.pop();
   		}while(!PQ.empty() && visited1[curr]);
   		if(visited1[curr]) break;

   		visited1[curr] = true;
   		int graph_size = graph[curr].size();
   		for (int i=0;i<graph_size;i++){
   			int next = graph[curr][i].first;
   			int d = graph[curr][i].second;
   			if (dist2[next] > dist2[curr]+d){
   				dist2[next] = dist2[curr] + d;
   				PQ.push(pii(dist2[next], next));
   			}
   		}
   }

   while(!PQ.empty()){
   	PQ.pop();
   }
  memset(visited1, 0, sizeof(visited1));
   
   PQ.push(pii(0,v_3));
   dist3[v_3] = 0;
   while (!PQ.empty()){
   		int curr;
   		do{
   			curr = PQ.top().second;
   			PQ.pop();
   		}while(!PQ.empty() && visited1[curr]);
   		if(visited1[curr]) break;

   		visited1[curr] = true;
   		int graph_size = graph[curr].size();
   		for (int i=0;i<graph_size;i++){
   			int next = graph[curr][i].first;
   			int d = graph[curr][i].second;
   			if (dist3[next] > dist3[curr]+d){
   				dist3[next] = dist3[curr] + d;
   				PQ.push(pii(dist3[next], next));
   			}
   		}
   }      
   vector<int> ans;
   for(int i=1;i<=n;i++){
   	int k=max(max(dist1[i],dist2[i]),dist3[i]);
  		ans.push_back(k);
   }
   int sda=*min_element(ans.begin(),ans.end());
   printf("%d",sda);
}