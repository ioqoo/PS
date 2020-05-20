#include <iostream>
#include <set>
#include <vector>
#include <queue>

#define pii pair<int, int>
const int MAX = 5005;
using namespace std;

int A, B, E, P;
int indeg[MAX];
vector<int> graph[MAX];
queue<int> Q;
int c[MAX]; // parents, children
set<int> S[MAX];


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d %d %d %d", &A, &B, &E, &P);
    int u, v;
    for (int i=0;i<P;i++){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        indeg[v]++;
        S[v].insert(u);
    }
    
    for (int i=0;i<E;i++){
        if (indeg[i] == 0) {
            Q.push(i);
        }
    }
    
    for (int i=1;i<=E;i++){
        int curr = Q.front();
        Q.pop();
        for (auto s: S[curr]){
            c[s]++;
        }
        for (int next: graph[curr]){
            for (auto s: S[curr]){
                S[next].insert(s);
            }
            if (--indeg[next] == 0){
                Q.push(next);
            }
        }
    }
    
//    for (int i=0;i<E;i++){
//        printf("succ : %d // pre : %d \n", S[i].size(), c[i]);
//    }
    
    int ansA = 0, ansB = 0, ansNO = 0;
    for (int i=0;i<E;i++){
        if (c[i] >= E-A) ansA++;
        if (c[i] >= E-B) ansB++;
        if (S[i].size() >= B) ansNO++;
    }
    
    printf("%d \n%d \n%d \n", ansA, ansB, ansNO);

    return 0;
}



