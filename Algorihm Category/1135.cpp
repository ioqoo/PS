#include <bits/stdc++.h>
#define all(vt) vt.begin(),vt.end()

const int MAX = 53;

using namespace std;

int N;
vector<int> graph[MAX];
int cnt[MAX];

bool cmp(const int &a, const int &b){
    return cnt[a] > cnt[b];
}

int solve(int curr){
    int ret = 0;
    
    for (auto next: graph[curr]){
        cnt[next] = solve(next) + 1;
    }
    
    sort(all(graph[curr]), cmp);
    for (int i=0;i<graph[curr].size();i++){
        ret = max(ret, cnt[graph[curr][i]] + i);
    }
    
    return ret;
    
//    
//    for (auto next: graph[curr]){
//        int next_val = solve(next);
//        if (max_val < next_val){
//            max_val = next_val;
//            max_cnt = 1;
//        }
//        else if (max_val == next_val){
//            max_cnt++;
//        }
//    }
//    printf("%d / %d\n", curr, max_val + max_cnt);
//    return ret;
}



int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d", &N);
    for (int v=0;v<N;v++){
        int u;
        scanf("%d", &u);
        if (u == -1) continue;
        graph[u].push_back(v);
    }
    printf("%d\n", solve(0));

    return 0;
}



