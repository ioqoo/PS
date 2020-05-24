#include <bits/stdc++.h>

const int MAX = 2000;
using namespace std;

int hp, wp, hm, wm;
vector<string> pattern;
vector<string> whole;
vector<string> column[MAX];
int fail[MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> hp >> wp >> hm >> wm;
    string row;
    for (int i=0;i<hp;i++){
        cin >> row;
        pattern.push_back(row);
    }
    
    for (int i=0;i<hm;i++){
        cin >> row;
        whole.push_back(row);
    }
    
    for (int j=0;j<hm;j++){
        for (int i=0;i<=wm-wp;i++){
            column[i].push_back(whole[j].substr(i, wp));
        }
    }
    
    
    for (int i=1, j=0;i<hp;i++){
        while(j>0 && pattern[i] != pattern[j]) j = fail[j-1];
        if (pattern[i] == pattern[j]) fail[i] = ++j;
    }
    
    int cnt = 0;
    
    for (int c=0;c<=wm-wp;c++){
        for (int i=0, j=0;i<hm;i++){
            while(j>0 && column[c][i] != pattern[j]) j = fail[j-1];
//            cout << column[c][i] << " " << pattern[j] << endl;
            if (column[c][i] == pattern[j]){
                if (j == hp-1){
                    cnt++;
                    j = fail[j];
                }
                else j++;
            }
        }
    }
    
    cout << cnt;
    

    return 0;
}



