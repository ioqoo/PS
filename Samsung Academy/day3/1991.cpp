#include <bits/stdc++.h>
#define MAX 10005
#define ll long long

using namespace std;

int N;
int tree[26][2];

void pre(int node){
    printf("%c", node+'A');
    int lc = tree[node][0], rc = tree[node][1];
    if (lc != -1) pre(lc);
    if (rc != -1) pre(rc);
}

void in(int node){
    int lc = tree[node][0], rc = tree[node][1];
    if (lc != -1) in(lc);
    printf("%c", node+'A');
    if (rc != -1) in(rc);
}

void post(int node){
    int lc = tree[node][0], rc = tree[node][1];
    if (lc != -1) post(lc);
    if (rc != -1) post(rc);
    printf("%c", node+'A');
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);

    scanf("%d\n", &N);

    memset(tree, -1, sizeof(tree));

    for (int i=0;i<N;i++){
        char p, c1, c2;
        scanf("%c %c %c\n", &p, &c1, &c2);
        int P = p - 'A';
        if (c1 != '.'){
            int C1 = c1 - 'A';
            tree[P][0] = C1;
        }
        if (c2 != '.'){
            int C2 = c2 - 'A';
            tree[P][1] = C2;
        }
    }

    pre(0);
    printf("\n");
    in(0);
    printf("\n");
    post(0);

    return 0;
}
