#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second

using namespace std;

vector<int> ans;
bool appear[101];
string seq;
bool succ;

void bt(int pos){
    if (succ) return;

//    for (int n : ans){
//        cout << n << " ";
//    }
//    cout << "\n";

    if (pos >= seq.size()){
        int N = ans.size();
        for (int i=1;i<=N;i++){
            if (!appear[i]) return;
        }
        for (int n: ans){
            cout << n << " ";
        }
        succ = true;
        return;
    }

    char a = seq[pos];
    if (!appear[a-'0']) {
        appear[a-'0'] = true;
        ans.push_back(a-'0');
        bt(pos+1);
        ans.pop_back();
        appear[a-'0'] = false;
    }
    if (pos < seq.size() - 1){
        char b = seq[pos+1];
        int ab = (a-'0')*10 + (b-'0');
        if (!appear[ab]) {
            appear[ab] = true;
            ans.push_back(ab);
            bt(pos + 2);
            ans.pop_back();
            appear[ab] = false;
        }
    }

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> seq;
    bt(0);

}
