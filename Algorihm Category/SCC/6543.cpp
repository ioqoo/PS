#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>

const int MAX = 5005;

using namespace std;

int N, M, sccnum;
int order[MAX], sn[MAX], sccoutdeg[MAX];
bool finished[MAX], sccans[MAX];
vector<int> graph[MAX];
stack<int> st;
int cnt;

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
            int t = st.top();
            st.pop();
            sn[t] = sccnum;
            finished[t] = true;
            if (t == curr) break;
        }
        sccnum++;
    }
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    while(1){
        scanf("%d", &N);
        if (N==0) return 0;
        scanf("%d", &M);
        sccnum = 0, cnt = 0;
        memset(order, 0, sizeof(order));
        memset(sn, 0, sizeof(sn));
        memset(finished, 0, sizeof(finished));
        memset(sccoutdeg, 0, sizeof(sccoutdeg));
        memset(sccans, 0, sizeof(sccans));
        for (int i=0;i<N;i++){
            graph[i].clear();
        }
        
        int u, v;
        for (int i=0;i<M;i++){
            scanf("%d %d", &u, &v);
            u--; v--;
            graph[u].push_back(v);
        }
        for (int i=0;i<N;i++){
            if (order[i] == 0) dfs(i);
        }
        
        for (int i=0;i<N;i++){
            int currsn = sn[i];
            for (int next: graph[i]){
                int nextsn = sn[next];
                if (currsn != nextsn){
                    sccoutdeg[currsn]++;
                }
            }
        }
        for (int i=0;i<sccnum;i++){
            if (sccoutdeg[i] == 0) sccans[i] = true;
        }

        for (int i=0;i<N;i++){
            if (sccans[sn[i]]) printf("%d ", i+1);
        }
        printf("\n");
    }

    return 0;
}



