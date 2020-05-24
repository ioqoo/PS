#include <bits/stdc++.h>

#define ll long long
using namespace std;

int N, SIZE;
vector<string> wordlist;
set<char> letters;
vector<char> letterlist;
bool used[10];
map<char, int> mp;

int cnt;

ll strtoLL(string word){
    int word_size = word.size();
    if (mp[word[0]] == 0) return -1LL;
    ll ret = 0;
    ll digit = 1;
    for (int i=word_size-1;i>=0;i--){
        int curr = word[i];
        ret += mp[curr] * digit;
        digit *= 10;
    }
    return ret;
}

void path(int idx){
    if(idx==SIZE){
        ll temp = 0;
        for (int i=0;i<N-1;i++){
            ll temp2 = strtoLL(wordlist[i]);
            if (temp2 != -1){
                temp += temp2;
            }
            else return;
        }
        if (temp == strtoLL(wordlist[N-1])) cnt++;
        return;
    }
    
    
    char now = letterlist[idx];
    for(int i=0; i<10; ++i){
        if(!used[i]){
            mp[now] = i;
            used[i] = true;
            path(idx+1);
            used[i] = false;
        }
    }
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    string word;
    for (int i=0;i<N;i++){
        cin >> word;
        wordlist.push_back(word);
        for (char c: word){
            if (!letters.count(c)) letterlist.push_back(c);
            letters.insert(c);
        }
    }
    SIZE = letterlist.size();
    
    path(0);
    cout << cnt;
//    printf("%d\n", cnt);

    return 0;
}



