#include <iostream>
#include <vector>

#define MAX 10005

using namespace std;

int V, E;
vector<int> graph[MAX];
int cnt;
int order[MAX];
int ans_cnt;
int LOW[MAX];
bool ans[MAX];

int DFS(int curr, bool is_Root){
    order[curr] = ++cnt;
    
    int ret = order[curr];
    int child = 0;
    for (auto next: graph[curr]){
        if (!order[next]){
            child++;
            int low = DFS(next, false);
            if (!is_Root && order[curr] <= low){
                ans[curr] = true;
            }
            ret = min(ret, low);
        }
        else{
            ret = min(ret, order[next]);
        }
    }
    
    if (is_Root){
        ans[curr] = (child >= 2);
    }
    
    LOW[curr] = ret;
    return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d %d", &V, &E);
	int u, v;
	for (int i=0;i<E;i++){
	    scanf("%d %d", &u, &v);
	    graph[u].push_back(v);
	    graph[v].push_back(u);
    }
    
    for (int i=1;i<=V;i++){
        if (!order[i]){
            DFS(i, true);
        }
    }
    for (int i=1;i<=V;i++){
        printf("%2d ", i);
    }
    printf("\n");
    
    for (int i=1;i<=V;i++){
        printf("%2d ", order[i]);
    }
    printf("\n");
    for (int i=1;i<=V;i++){
        printf("%2d ", LOW[i]);
    }
    printf("\n");
    
    
    for (int i=1;i<=V;i++){
        if (ans[i]) ans_cnt++;
    }
    
    printf("%d\n", ans_cnt);
    for (int i=1;i<=V;i++){
        if (ans[i]){
            printf("%d ", i);
        }
    }
	
	

	return 0;
}
