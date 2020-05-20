#include <iostream>
#include <vector>
#include <stack>
#include <queue>

const int MAX = 10005;

using namespace std;

int N, M, S, T, sccnum, cnt, startsn, endsn;
int order[MAX], sn[MAX], sccindeg[MAX], sccval[MAX], sccmax[MAX];
vector<int> graph[MAX], sccgraph[MAX];
bool finished[MAX], cango[MAX];
stack<int> st;
queue<int> Q;

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
            sccmax[sn[t]]++;
            sccval[sn[t]]++;
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
    
    scanf("%d %d %d %d", &N, &M, &S, &T);
    S--; T--;
    int u, v;
    for (int i=0;i<M;i++){
        scanf("%d %d", &u, &v);
        u--; v--;
        graph[u].push_back(v);
    }
    
    for (int i=0;i<N;i++){
        if (order[i] == 0) dfs(i);
    }
    
    startsn = sn[S], endsn = sn[T];
    
    for (int curr=0;curr<N;curr++){
        int currsn = sn[curr];
        for (int next: graph[curr]){
            int nextsn = sn[next];
            if (currsn != nextsn){
                sccgraph[currsn].push_back(nextsn);
                sccindeg[nextsn]++;
            }
        }
    }
    
    cango[startsn] = true;
    for (int i=0;i<sccnum;i++){
        if (sccindeg[i] == 0) Q.push(i);
    }
    
    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        for (int next: sccgraph[curr]){
            if (cango[curr]) {
                sccmax[next] = max(sccmax[next], sccmax[curr] + sccval[next]);
                cango[next] = true;
            }
            if (--sccindeg[next] == 0) Q.push(next);
        }
    }
    if (cango[endsn]) printf("%d\n", sccmax[endsn]);
    else printf("0\n");
    

    return 0;
}



