#include <iostream>
#include <cstring>

#define MAX 100005

using namespace std;

int G, P;
int p[MAX];

int find(int node){
    if (p[node] == -1) return node;
    return p[node] = find(p[node]);
}



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d %d", &G, &P);
    int curr;
    int ans = 0;
    memset(p, -1, sizeof(p));
    for (int i=0;i<P;i++){
        scanf("%d", &curr);
        if (find(curr) == -1){
            ans++;
            p[curr] = curr-1;
        }
        else if (find(curr) == 0){
            break;
        }
        else{
            ans++;
            p[find(curr)] = find(curr) - 1;
        }
    }
    printf("%d\n", ans);

    return 0;
}

