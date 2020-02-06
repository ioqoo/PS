#include <bits/stdc++.h>

using namespace std;

int N;
string ans;

void bt(int len, char c)
{
    if (len == N + 1) {
        cout << ans << "\n";
        exit(0);
    }

    ans += c;

    for (int i=1;i<=len/2;i++){
        string a = ans.substr(len - 2*i, i);
        string b = ans.substr(len - i, i);

        if (a == b) {
            ans.erase(len - 1);
            return;
        }
    }

    for (int i=1;i<=3;i++){
        bt(len + 1, i + '0');
    }
    ans.erase(len-1);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    cin >> N;

    bt(1, '1');
}
