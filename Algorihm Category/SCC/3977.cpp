#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

const int MAX = 100005;

using namespace std;

int T, N, M, sccnum, cnt;
int order[MAX], sn[MAX], sccindeg[MAX];
bool finished[MAX];
vector<int> graph[MAX];
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
    
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        sccnum = 0, cnt = 0;
        memset(order, 0, sizeof(order));
        memset(sn, 0, sizeof(sn));
        memset(finished, 0, sizeof(finished));
        memset(sccindeg, 0, sizeof(sccindeg));
        for (int i=0;i<N;i++){
            graph[i].clear();
        }
        
        int u, v;
        for (int i=0;i<M;i++){
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
        }
        
        for (int i=0;i<N;i++){
            if (order[i] == 0) dfs(i);
        }
        
        for (int i=0;i<N;i++){
            int currsn = sn[i];
            for (int next: graph[i]){
                int nextsn = sn[next];
                if (currsn != nextsn) {
                    sccindeg[nextsn]++;
                }
            }
        }
        
        
        int zerocnt = 0, anssccnum;
        for (int i=0;i<sccnum;i++){
            if (sccindeg[i] == 0) {
                zerocnt++;
                anssccnum = i;
            }
        }
        if (zerocnt != 1) printf("Confused\n");
        else{
            for (int i=0;i<N;i++){
                if (sn[i] == anssccnum) printf("%d\n", i);
            }
        }
        printf("\n");
    }

    return 0;
}



