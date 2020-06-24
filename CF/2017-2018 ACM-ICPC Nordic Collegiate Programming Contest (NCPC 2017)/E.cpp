#include <bits/stdc++.h>

const int INF = 100;
const int MAX = 100005;
using namespace std;

int N, K;
int curr;
int sim[MAX];
bool visited[1<<21];
vector<int> grid;
int big = INF;
int ans;


string make_ans(int st){
    
    string ret;
    while(st){
        if(st%2) ret+='1';
        else ret += '0';
        st/=2;
    }
    while(ret.length() < K) ret +='0';
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d %d", &N, &K);
    
    grid.resize(N);
    for (int i=0;i<N;i++){
        for (int j=K-1;j>=0;j--){
            int temp;
            scanf("%1d", &temp);
            if (temp) grid[i] |= (1 << j);
        }
    }
    
    for (int j=0;j<K;j++){
        int onecnt = 0;
        for (int i=0;i<N;i++){
            if ((grid[i] & (1<<j)) != 0){
                onecnt++;
            }
        }
        if (onecnt <= N - onecnt){
            curr |= (1<<j);
        }
    }
    
    curr = 7;
    
    for (int i=0;i<N;i++){
        for (int j=0;j<K;j++){
            if ((curr & (1<<j)) == (grid[i] & (1<<j))){
                sim[i]++;
            }
        }
    }
    
    int maxi = 
    
    ans = curr;

    for (int i=0;i<K;i++){
        solve(i);
    }
   
   cout << make_ans(ans) << '\n';
   
    return 0;
}



