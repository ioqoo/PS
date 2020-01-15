#include <bits/stdc++.h>
#define ll long long
#define MAX 1234567890

using namespace std;

vector<int> graph[2005];
int N, M, K;
int dest_pos[2005];
bool is_dest[2005];
bool check[2005];
vector<int> ans;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &N, &M);
    for (int i=0;i<M;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    scanf("%d", &K);
    for (int i=0;i<K;i++){
        int temp;
        scanf("%d", &temp);
        dest_pos[i] = temp;
        is_dest[temp] = true;
    }
    for (int i=0;i<K;i++){
        int pos = dest_pos[i];
        bool flag = true;
        for (int j=0;j<graph[pos].size();j++){
            if (is_dest[graph[pos][j]] == false){
                flag = false;
                break;
            }
        }
        if (flag) ans.push_back(pos);
    }
    for (int i=0;i<ans.size();i++){
        check[ans[i]] = true;
        for (int j=0;j<graph[ans[i]].size();j++){
            check[graph[ans[i]][j]] = true;
        }
    }

    int cnt = 0;
    for (int i=0;i<=N;i++){
        if (check[i]) cnt++;
    }
    if (cnt < K){
        printf("-1");
    } // ansµé·Î ½ÇÁ¦ ÆøÅºÀ» ¶³¾î¶ß·Á º»´ÙÀ½ ÆÄ±«µÈ µµ½Ã °³¼ö°¡
      // Kº¸´Ù ÀÛÀ» ¶© -1
    else{
        printf("%d\n", ans.size());
        for (int i=0;i<ans.size();i++){
            printf("%d ", ans[i]);
        }
    }
    return 0;
}
