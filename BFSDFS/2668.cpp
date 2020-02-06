#include <bits/stdc++.h>
#define MAX 105

using namespace std;

int N;
int E[MAX];
bool visited[MAX];
bool finished[MAX];
vector<int> ans;

void DFS(int curr){
    visited[curr] = true;
    int next = E[curr];
    if (visited[next]){
        if (!finished[next]){
            for (int start = next; start != curr; start = E[start]) {
                ans.push_back(start);
            }
            ans.push_back(curr);
        }
    }
    else DFS(next);

    finished[curr] = true;

}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        scanf("%d", &E[i]);
    }
    for (int i=1;i<=N;i++){
        if (!visited[i]) DFS(i);
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int n: ans){
        printf("%d\n", n);
    }
}
