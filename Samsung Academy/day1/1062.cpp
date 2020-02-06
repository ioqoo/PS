#include <bits/stdc++.h>
#define MAX 55

using namespace std;

bool alpha[MAX][26];
bool choice[26];
int N, K;
int ans;

void solve(int pos, int cnt){
    if (cnt == K - 5){
        int ret = 0;
        for (int i=0;i<N;i++){
            bool succ = true;
            for (int c=0;c<26;c++){
                if (c == 'a' - 'a' || c == 'n' - 'a' || c == 't' - 'a' || c == 'i' - 'a' || c == 'c' - 'a'){
                    continue;
                }
                if (!alpha[i][c]) continue;

                if (!choice[c]) {
                    succ = false;
                    break;
                }
            }
            if (succ) ret++;
        }

        ans = max(ans, ret);
        return;
    }

    for (int j=pos+1;j<26;j++){
        if (j == 'a' - 'a' || j == 'n' - 'a' || j == 't' - 'a' || j == 'i' - 'a' || j == 'c' - 'a'){
            continue;
        }
        choice[j] = true;
        solve(j, cnt+1);
        choice[j] = false;
    }

    return;

}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    if (K < 5) {
        cout << "0\n";
        return 0;
    }
    for (int x=0;x<N;x++){
        string temp;
        cin >> temp;
        int word_size = temp.size();
        for (int i=0;i<word_size;i++){
            if (temp[i] == 'a' || temp[i] == 'n' || temp[i] == 't' || temp[i] == 'i' || temp[i] == 'c'){
                continue;
            }
            alpha[x][temp[i]-'a'] = true;
        }
    }

    if (K == 5){
        solve(0, 0);
    }
    else{
        for (int i=0;i<26;i++){
            if (i == 'a' - 'a' || i == 'n' - 'a' || i == 't' - 'a' || i == 'i' - 'a' || i == 'c' - 'a'){
                continue;
            }
            choice[i] = true;
            solve(i, 1);
            choice[i] = false;
        }
    }

    cout << ans;

    return 0;

}
