#include <bits/stdc++.h>
#define MAX 10005

using namespace std;

int N, M;
vector<int> graph[MAX];
bool visited[MAX];
vector<int> ans_nums;
int maximum;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &N, &M);
    for (int i=0;i<M;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        graph[v].push_back(u); // v -> u
    }

    for (int i=1;i<=N;i++){
        int curr_max = 0;
        memset(visited, 0, sizeof(visited));
        queue<int> q;
        q.push(i);
        visited[i] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for (int v: graph[u]){
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        for (int j=1;j<=N;j++){
            if (visited[j]) curr_max++;
        }
        if (curr_max > maximum){
            ans_nums.clear();
            ans_nums.push_back(i);
            maximum = curr_max;
        }
        else if (curr_max == maximum){
            ans_nums.push_back(i);
        }
    }
    for (int n: ans_nums){
        printf("%d ", n);
    }
}
