#include <bits/stdc++.h>

using namespace std;

struct query{
    int x, a, b;
};

int p[200005];

int find(int node){
    if (p[node] == -1) return node;
    return p[node] = find(p[node]);
}

void merge(int nodea, int nodeb){
    int roota = find(nodea);
    int rootb = find(nodeb);
    if (roota == rootb) return;
    p[roota] = rootb;
    return;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    memset(p, -1, sizeof(p));
    int N, Q;
    scanf("%d %d", &N, &Q);
    vector<query> query_list;
    int parent_num[200005];
    for (int i=2;i<=N;i++){
        int temp;
        scanf("%d", &temp);
        parent_num[i] = temp;
    }
    for (int i=0;i<N+Q-1;i++){
        int x, a, b;
        scanf("%d", &x);
        if (x == 0){
            scanf("%d", &a);
            query_list.push_back({x, a, -1});
        }
        else{
            scanf("%d %d", &a, &b);
            query_list.push_back({x, a, b});
        }
    }
    vector<int> ans;
    for (auto q=query_list.rbegin();q!=query_list.rend();q++){
        auto curr_q = *q;
        if (curr_q.x == 0){
            merge(curr_q.a, parent_num[curr_q.a]);
        }
        else{
            if (find(curr_q.a) == find(curr_q.b)){
                ans.push_back(1);
            }
            else ans.push_back(0);
        }
    }
    for (auto it=ans.rbegin();it!=ans.rend();it++){
        printf((*it)==1?"YES\n":"NO\n");
    }

    return 0;
}



