#include <bits/stdc++.h>

#define MAX 55

using namespace std;

int T, R, C, K;
char grid[MAX][MAX];
int graph[MAX][MAX];
string row;
vector<string> words;
int cnt = 1;

void dfs(int a, int b, bool hori, int ind){
    if (a < 0 || a >= R || b < 0 || b >= C) return;
    if (graph[a][b] != 0 || grid[a][b] == '#') return;
    
    
    graph[a][b] = ind;
    if (hori){
        dfs(a, b+1, true, cnt);
        dfs(a+1, b, false, ++cnt);
    }
    else{
        dfs(a, b+1, true, ++cnt);
        dfs(a+1, b, false, cnt);;
    }
    
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> T;
    while(T>0){
        T--;
        
        cnt = 1;
        cin >> R >> C >> K;
        memset(graph, 0, sizeof(graph));
        words.clear();
        
        for (int i=0;i<R;i++){
            cin >> row;
            for (int j=0;j<C;j++){
                grid[i][j] = row[j];
            }
        }
        string temp;
        for (int i=0;i<K;i++){
            cin >> temp;
            words.push_back(temp);
        }
        
        for (int i=0;i<R;i++){
            for (int j=0;j<C;j++){
                dfs(i, j, true, cnt);
            }
        }
        for (int i=0;i<R;i++){
            for (int j=0;j<C;j++){
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        
    }

    return 0;
}

