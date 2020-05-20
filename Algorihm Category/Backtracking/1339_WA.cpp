#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N;
ll let[26];
int kind;
vector<string> words;
ll ans;


ll str_to_int(string a){
    ll ret = 0LL, len = a.size(), digit = 1LL;

    for (int i=len-1;i>=0;i--){
        char c = a[i];
        ret += let[c - 'A'] * digit;
        digit *= 10LL;
    }

    return ret;
}

void make_permutation(vector<int> ch){
    int ch_size = ch.size();
    if (ch_size == kind) {

        int cnt = 0;
        for (int i=0;i<26;i++){
            if (let[i]) {
                let[i] = ch[cnt];
                cnt++;
            }
        }

        ll curr = 0LL;
        for (auto s: words){
            curr += str_to_int(s);
        }
        ans = max(ans, curr);

        return;
    }

    for (int i=9;i>9-kind;i--){
        if (!count(ch.begin(), ch.end(), i)) {
            ch.push_back(i);
            make_permutation(ch);
            ch.pop_back();
        }
    }
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int x=0;x<N;x++){
        string temp;
        cin >> temp;
        for (char c: temp){
            let[c-'A'] = 1;
        }
        words.push_back(temp);
    }
    for (int i=0;i<26;i++){
        if (let[i]) kind++;
    }

    for (int i=9;i>9-kind;i--){
        vector<int> ch;
        ch.push_back(i);
        make_permutation(ch);
        ch.pop_back();
    }

    cout << ans;
}
