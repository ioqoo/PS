#include <iostream>
#include <cstring>

#define MAX 20005

using namespace std;

int T;
int N;
int p[MAX];
int dist[MAX];

int find(int node){
    if (p[node] == -1) return node;
    
    int parent = find(p[node]);
    dist[node] += dist[p[node]];
    return p[node] = parent;
}

void merge(int a, int b, int w){
    int roota = find(a);
    int rootb = find(b);
    if (roota == rootb) return;
    dist[roota] = dist[b] + w - dist[a];
    p[roota] = rootb;
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &T);
    while(T>0){
        T--;
        
        memset(p, -1, sizeof(p));
        memset(dist, 0, sizeof(dist));
        scanf("%d", &N);
        char op;
        int a, b;
        while(1){
            scanf(" %c ", &op);
            if (op == 'O') break;
            else if (op == 'E') {
                scanf("%d", &a);
                find(a);
                printf("%d\n", dist[a]);
            }
            else if (op == 'I'){
                scanf("%d %d", &a, &b);
                merge(a, b, abs(a-b)%1000);
            }
        }
    }

    return 0;
}

