#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>

const int MAX = 100005;

using namespace std;

int T, N, M, sccnum;
int order[MAX], sn[MAX];
bool finished[MAX];
vector<int> graph[MAX];
int sccindeg[MAX];
int cnt;
stack<int> st;

int dfs(int curr){
    order[curr] = ++cnt;
    st.push(curr);
    int ret = order[curr];
    for (int next: graph[curr]){
        if (order[next] == 0) ret = min(ret, dfs(next));
        else if (!finished[next]) ret = min(ret, order[next]);
    }
    
    if (ret == order[curr]){
        while(1){
            int n = st.top();
            st.pop();
            sn[n] = sccnum;
            finished[n] = true;
            if (n == curr) break;
        }
        sccnum++;
    }
    
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        memset(order, 0, sizeof(order));
        memset(sn, 0, sizeof(sn));
        memset(finished, 0, sizeof(finished));
        memset(sccindeg, 0, sizeof(sccindeg));
        cnt = 0, sccnum = 0;
        fill(graph, graph+N, vector<int> ());
        
        int u, v;
        for (int i=0;i<M;i++){
            scanf("%d %d", &u, &v);
            u--; v--;
            graph[u].push_back(v);
        }
        for (int i=0;i<N;i++){
            if (order[i] == 0) dfs(i);
        }
        
        for (int curr=0;curr<N;curr++){
            int currsn = sn[curr];
            for (int next: graph[curr]){
                int nextsn = sn[next];
                if (currsn != nextsn){
                    sccindeg[nextsn]++;
                }
            }
        }
        int ans = 0;
        for (int i=0;i<sccnum;i++){
            if (sccindeg[i] == 0) ans++;
        }
        
        printf("%d\n", ans);
        
    }
    

    return 0;
}



