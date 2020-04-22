#include <iostream>
#include <vector>
#include <cstring>

#define ll long long
#define MAX 20005

using namespace std;

int N;
int num[MAX];
int p[MAX];
bool visited[MAX];
ll ans;
ll gcd = -1;
ll lcm = 1;

ll GCD(ll a, ll b){
    if (a < b) swap(a, b);
    while(b>0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int find(int node){
    if (p[node] <= -1) return node;
    return p[node] = find(p[node]);
}

void merge(int a, int b){
    int roota = find(a);
    int rootb = find(b);
    if (roota == rootb) return;
    p[rootb] += p[roota];
    p[roota] = rootb;
    return;
}

void DFS(int node){
    int nextpos = num[node];
    if (visited[nextpos]) return;
    merge(node, nextpos);
    visited[nextpos] = true;
    DFS(nextpos);
    return;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        int temp;
        scanf("%d", &temp);
        num[i] = temp-1;
    }
    
    memset(p, -1, sizeof(p));
    
    for (int i=0;i<N;i++){
        if (visited[i]) continue;
        visited[i] = true;
        DFS(i);
    }
    
    vector<ll> temp;
    for (int i=0;i<N;i++){
        if (p[i] < -1){
            temp.push_back(-(ll)p[i]);
        }
    }
    
    for (int i=0;i<temp.size();i++){
        if (i==0){
            lcm = temp[0];
            gcd = temp[0];
        }
        gcd = GCD(lcm, temp[i]);
        lcm = lcm*temp[i]/gcd;
    }
    
    
    
    
    printf("%lld\n", lcm);
    
    

    return 0;
}



