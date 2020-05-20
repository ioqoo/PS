#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

const int MAX = 10005;
using namespace std;

int V, E;
int dfsn[MAX];
bool finished[MAX]; // visit? -> dfsn[i] != 0 
vector<int> graph[MAX];
vector<vector<int>> SCC;
int cnt;
stack<int> st;

int DFS(int curr){
    dfsn[curr] = ++cnt;
    st.push(curr);
    
    int ret = dfsn[curr];
    for (int next: graph[curr]){
        if (dfsn[next] == 0) ret = min(ret, DFS(next));
        else if (!finished[next]) ret = min(ret, dfsn[next]);
    }
    
    if (ret == dfsn[curr]){
        vector<int> currSCC;
        while(true){
            int n = st.top();
            st.pop();
            currSCC.push_back(n);
            finished[n] = true;
            if (n == curr) break;
        }
        
        sort(currSCC.begin(), currSCC.end());
        SCC.push_back(currSCC);
    }
    return ret;
    
} 

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d %d", &V, &E);
    int u, v;
    for (int i=0;i<E;i++){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
    }
    for (int i=1;i<=V;i++){
        if (dfsn[i] == 0) DFS(i);
    }
    
    sort(SCC.begin(), SCC.end());
    
    printf("%d\n", SCC.size());
    for (auto p: SCC){
        for (int curr: p){
            printf("%d ", curr);
        }
        printf("-1\n");
    }

    return 0;
}



