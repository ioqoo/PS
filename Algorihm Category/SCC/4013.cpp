 #include <iostream>
#include <vector>
#include <queue>
#include <stack>

const int MAX = 500005;

using namespace std;

int N, M, S, P, sccnum, startsn;
vector<int> graph[MAX];
int cash[MAX], sn[MAX], order[MAX];
bool isrest[MAX], hasrest[MAX], finished[MAX], cango[MAX];
int scash[MAX];
int sccindeg[MAX];
int sccmax[MAX];
vector<int> sccgraph[MAX];
stack<int> st;
queue<int> Q;
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
        while(true){
            int t = st.top();
            st.pop();
            sn[t] = sccnum;
            scash[sn[t]] += cash[t];
            if (isrest[t]) hasrest[sn[t]] = true;
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
    
    scanf("%d %d", &N, &M);
    int u, v;
    for (int i=0;i<M;i++){
        scanf("%d %d", &u, &v);
        u--; v--;
        graph[u].push_back(v);
    }
    for (int i=0;i<N;i++){
        scanf("%d", &cash[i]);
    }
    
    scanf("%d %d", &S, &P);
    S--;
    
    int temp;
    for (int i=0;i<P;i++){
        scanf("%d", &temp);
        temp--;
        isrest[temp] = true;
    }
    
    for (int i=0;i<N;i++){
        if (order[i] == 0) dfs(i);
    }
    
    startsn = sn[S];
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
        sccmax[i] = scash[i];
        if (sccindeg[i] == 0) Q.push(i);
    }
    
    while(!Q.empty()){
        int currsn = Q.front();
        Q.pop();
        for (int nextsn: sccgraph[currsn]){
            if (cango[currsn]) {
                sccmax[nextsn] = max(sccmax[nextsn], sccmax[currsn] + scash[nextsn]);
                cango[nextsn] = true;
            }
            if (--sccindeg[nextsn] == 0) Q.push(nextsn);
        }
    }
    int ans = 0;
    for (int i=0;i<sccnum;i++){
        if (hasrest[i] && cango[i]) ans = max(ans, sccmax[i]);
    }
    printf("%d\n", ans);
    
    

    return 0;
}



