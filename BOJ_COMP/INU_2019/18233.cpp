// https://www.acmicpc.net/problem/18233

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int N, P, E;
pair<int, pii> mem[20];
int ans[20];
bool succ = false;

void backtrack(int i, vector<pair<int, pii>> ch){
    if (succ) return;

    if (ch.size() == P){
        int minimum = 0;
        int maximum = 0;
        for (auto p: ch){
            minimum += p.second.first;
            maximum += p.second.second;
        }

        if (minimum <= E && E <= maximum){
            int remain = E;
            for (auto p: ch){
                ans[p.first] += p.second.first;
                remain -= p.second.first;
            }
            for (auto p: ch){
                ans[p.first] += min(remain, p.second.second - p.second.first);
                remain -= min(remain, p.second.second - p.second.first);
                if (remain <= 0) break;
            }
            succ = true;
            return;
        }
    }
    for (int j=i+1;j<N;j++){
        ch.push_back(mem[j]);
        backtrack(j, ch);
        ch.pop_back();
    }
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d %d", &N, &P, &E);
    for (int i=0;i<N;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        mem[i] = make_pair(i, pii(x, y));
    }

    for (int i=0;i<N;i++){
        vector<pair<int, pii>> chh;
        chh.push_back(mem[i]);
        backtrack(i, chh);
        chh.pop_back();
    }
    if (!succ) printf("-1");
    else{
        for (int i=0;i<N;i++){
            printf("%d ", ans[i]);
        }
    }


    return 0;
}
