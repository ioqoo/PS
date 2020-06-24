#include <bits/stdc++.h>

const int MAX = 100005;
using namespace std;

int N, s, t;
vector<int> graph[MAX];
int depth[MAX];
bool succ[MAX];
bool visited[MAX];

int makedepth(int curr){
    for (int next:graph[curr]){
        if (depth[next] == -1) {
            depth[next] = depth[curr] + 1;
            makedepth(next);
        }
    }
}

int makesucc(int curr){
    if (curr == t) return succ[curr] = true;
    bool ret = false;
    visited[curr] = true;
    for (int next: graph[curr]){
        if (visited[next]) continue;
        ret |= makesucc(next);
        
    }
    return succ[curr] = ret;
}

vector<int> dfssucc(int curr){}
vector<int> dfsnonsucc(int curr){}

vector<int> dfssucc(int curr){
    vector<int> ret;
    ret.push_back(curr);
    for (int next:graph[curr]){
        if (succ[next]){
            for (int n: dfssucc(next)){
                ret.push_back(n);
            }
        }
        else{
            for (int n: dfsnonsucc(next)){
                ret.push_back(n);
            }
        }
    }
    return ret;
}

vector<int> dfsnonsucc(int curr){
    vector<int> ret;
    for (int next: graph[curr]){
        if (succ[next]){
            for (int n: dfssucc(next)){
                ret.push_back(n);
            }
        }
        else{
            for (int n: dfsnonsucc(next)){
                ret.push_back(n);
            }
        }
    }
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    scanf("%d", &N);
    for (int i=0;i<N-1;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    scanf("%d %d", &s, &t);
    memset(depth, -1, sizeof(depth));
    depth[s] = 0;
    makedepth(s);
    
    makesucc(s);
    
    
    

    return 0;
}



