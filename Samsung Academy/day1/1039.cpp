#include <bits/stdc++.h>
#define MAX 20005

using namespace std;

string str;
int K;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> str >> K;

    queue<string> q;
    q.push(str);

    for (int x=0;x<K;x++){
        int q_size = q.size();
        set<string> s;
        for (int n=0;n<q_size;n++){
            string curr = q.front();
            q.pop();
            if (s.count(curr)) continue;
            s.insert(curr);

            for (int i=0;i<str.size()-1;i++){
                for (int j=i+1;j<str.size();j++){
                    if (i>0 || curr[j] != '0'){
                        swap(curr[i], curr[j]);
                        q.push(curr);
                        swap(curr[i], curr[j]);
                    }
                }
            }
        }
    }

    string ans = "0";

    while(!q.empty()){
        ans = max(ans, q.front());
        q.pop();
    }
    if (ans[0] == '0') cout << "-1\n";
    else cout << ans;

    return 0;

}
