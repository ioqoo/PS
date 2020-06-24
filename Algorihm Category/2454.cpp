#include <bits/stdc++.h>

#define pii pair<int, int>
const int MAX = 300005;

using namespace std;
int N, K;
vector<int> graph[MAX];
bool visited[MAX];

// pair(remain, part)
pii solve(int curr){
    visited[curr] = true;
    int remainfirst = 0, remainsecond = 0, totalpart = 0;
    for (int next: graph[curr]){
        if (visited[next]) continue;
        pii temp = solve(next);
        if (remainfirst < temp.first){
            remainsecond = remainfirst;
            remainfirst = temp.first;
        }
        else if (remainfirst == temp.first){
            remainsecond = temp.first;
        }
        else{
            if (remainsecond < temp.first){
                remainsecond = temp.first;
            }
        }
        totalpart += temp.second;
    }
    if (remainfirst == 0 && remainsecond == 0) return {K, totalpart + 1};
    
    if (remainfirst + remainsecond > K+1){ // enough
        return {0, totalpart-1};
    }
    else return {remainfirst-1, totalpart};
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d %d", &N, &K);
    int u, v;
    for (int i=0;i<N-1;i++){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    printf("%d\n", solve(1).second);
    
    

    return 0;
}



