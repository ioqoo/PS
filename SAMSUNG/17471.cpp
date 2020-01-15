#include <bits/stdc++.h>
#define ll long long
#define INF 987654321

using namespace std;

int N;
int pop[13];
vector<int> graph[13];
int ans = INF;
int p[13];

int find(int a){
    if (p[a]==-1) return a;

    p[a] = find(p[a]);
    return p[a];
}

void merge(int a, int b){
    int root1 = find(a);
    int root2 = find(b);
    if (root1 == root2) return;
    p[root1] = root2;
}

void split(vector<int> A, vector<int> B){
    for (int u: A){
        for (int v: graph[u]){
            if (!count(B.begin(), B.end(), v)){
                merge(u, v);
            }
        }
    }
    for (int u: B){
        for (int v: graph[u]){
            if (!count(A.begin(), A.end(), v)){
                merge(u, v);
            }
        }
    }
}

void bt(int z, vector<int> ch){
    memset(p, -1, sizeof(p));

    vector<int> ch2;
    for (int i=1;i<=N;i++){
        if (!count(ch.begin(), ch.end(), i)){
            ch2.push_back(i);
        }
    }
    split(ch, ch2);


//    printf("group 1 : ");
//    for (int i=0;i<ch.size();i++){
//        printf("%d ", ch[i]);
//    }
//    printf("\n");
//    printf("group 2 : ");
//    for (int i=0;i<ch2.size();i++){
//        printf("%d ", ch2[i]);
//    }
//    printf("\n");
//    printf("parents : ");
//    for (int i=0;i<N;i++){
//        printf("%d ", p[i]);
//    }
//    printf("\n\n");


    int comp = 0;
    for (int i=1;i<=N;i++){
        if (p[i] == -1) {
            comp++;
        }
    }
    if (comp == 2) {
        int group1 = 0, group2 = 0;
        for (int p: ch){
            group1 += pop[p];
        }
        for (int p: ch2){
            group2 += pop[p];
        }
        int result = abs(group1 - group2);
        ans = min(result, ans);
    }
    for (int i=z+1;i<=N;i++){
        ch.push_back(i);
        bt(i, ch);
        ch.pop_back();
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        scanf("%d", &pop[i]);
    }
    for (int u=1;u<=N;u++){
        int temp;
        scanf("%d", &temp);
        for (int j=0;j<temp;j++){
            int v;
            scanf("%d", &v);
            graph[u].push_back(v);
        }
    }
    for (int i=1;i<=N;i++){
        vector<int> ch;
        ch.push_back(i);
        bt(i, ch);
        ch.pop_back();
    }
    printf("%d\n", ans==INF ? -1 : ans);

}
