#include <iostream>
#include <cstring>

#define MAX 300005

using namespace std;

int N, L;
int p[MAX];
bool has[MAX];

int find(int node){
    if (p[node] == -1) return node;
    return p[node] = find(p[node]);
}

void merge(int a, int b){
    int roota = find(a);
    int rootb = find(b);
    if (roota == rootb) return;
    p[roota] = rootb;
    return;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d %d", &N, &L);
    memset(p, -1, sizeof(p));
    int a, b;
    for (int i=0;i<N;i++){
        scanf("%d %d", &a, &b);
        if (!has[a]) {
            has[a] = true;
            merge(a, b);
            printf("LADICA\n");
        }
        else if (!has[b]){
            has[b] = true;
            merge(b, a);
            printf("LADICA\n");
        }
        else if (!has[find(a)]){
            has[find(a)] = true;
            merge(find(a), b);
            printf("LADICA\n");
        }
        else if (!has[find(b)]){
            has[find(b)] = true;
            merge(find(b), a);
            printf("LADICA\n");
        }
        else printf("SMECE\n");
    }
    

    return 0;
}



