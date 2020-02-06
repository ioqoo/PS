#include <bits/stdc++.h>
#define MAX 20005

using namespace std;

int L, C;
vector<char> alpha;

void DFS(int pos, vector<int> ch){
    if (ch.size() == L) {
        int v_cnt = 0, c_cnt = 0;
        string ret = "";
        for (int n: ch){
            if (alpha[n] == 'a' || alpha[n] == 'e' || alpha[n] == 'i' || alpha[n] == 'o' || alpha[n] == 'u'){
                v_cnt++;
            }
            else c_cnt++;
            ret += alpha[n];
        }
        if (v_cnt >= 1 && c_cnt >= 2){
            cout << ret << "\n";
        }
        return;
    }


    for (int j=pos+1;j<C;j++){
        ch.push_back(j);
        DFS(j, ch);
        ch.pop_back();
    }
}



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    cin >> L >> C;
    for (int i=0;i<C;i++){
        char c;
        cin >> c;
        alpha.push_back(c);
    }

    sort(alpha.begin(), alpha.end());

    for (int i=0;i<=C-L;i++){
        vector<int> ch;
        ch.push_back(i);
        DFS(i, ch);
        ch.pop_back();
    }

    return 0;

}
