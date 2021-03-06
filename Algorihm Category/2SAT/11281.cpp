#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>

#define pii pair<int, int>
const int MAX = 10005;

using namespace std;

int N, M, sccnum, cnt;
int order[MAX*2], sn[MAX*2], ans[MAX];
bool finished[MAX*2];
vector<int> graph[MAX*2];
stack<int> st;
vector<pii> tsorder;

int makenot(int n){
    if (n%2) return n+1;
    else return n-1;
}

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

    scanf("%d %d", &N, &M);
    int u, v;
    for (int i=0;i<M;i++){
        scanf("%d %d", &u, &v);
        u = u>0 ? u*2-1 : (-u)*2;
        v = v>0 ? v*2-1 : (-v)*2;
        graph[makenot(u)].push_back(v);
        graph[makenot(v)].push_back(u);
    }
    
    for (int i=1;i<=N*2;i++){
        if (order[i] == 0) dfs(i);
    }
    
    for (int i=1;i<=N;i++){
        if (sn[i*2-1] == sn[i*2]) {
            printf("0\n");
            return 0;
        }
    }
    printf("1\n");
    memset(ans, -1, sizeof(ans));
    for (int i=1;i<=N*2;i++){
        tsorder.push_back(pii(sn[i], i));
    }
    sort(tsorder.begin(), tsorder.end(), greater<pii>());
    for (auto p: tsorder){
        int curr = p.second;
        if (ans[(curr+1)/2] == -1){ // 1 : x1, 2 : !x1
            ans[(curr+1)/2] = curr%2 ? 0 : 1;
        }
    }
    for (int i=1;i<=N;i++){
        printf("%d ", ans[i]);
    }
    


    return 0;
}



