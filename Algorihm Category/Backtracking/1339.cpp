#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int N;
ll let[26];
vector<pii> order;
vector<string> words;


void eq(string a){
    int len = a.size(), digit = 1LL;
    for (int i=len-1;i>=0;i--){
        char c = a[i];
        let[c-'A'] += digit;
        digit *= 10LL;
    }
}

ll str_to_int(string a){
    ll ret = 0LL, len = a.size(), digit = 1LL;

    for (int i=len-1;i>=0;i--){
        char c = a[i];
        ret += let[c - 'A'] * digit;
        digit *= 10LL;
    }

    return ret;
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
        eq(temp);
        words.push_back(temp);
    }

    for (int i=0;i<26;i++){
        if (let[i]) {
            order.push_back(pii(let[i], i));
        }
    }
    sort(order.begin(), order.end(), greater<pii>());

    int num = 9;
    for (auto p: order){
        let[p.second] = num;
        num--;
    }

    ll ans = 0LL;
    for (auto s: words){
        ans += str_to_int(s);
    }
    cout << ans;
}
