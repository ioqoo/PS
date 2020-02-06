#include <bits/stdc++.h>
#define MAX 10005
#define ll long long

using namespace std;

int M;
set<int> S;
set<int> all;
set<int> E;


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> M;

    for (int i=1;i<=20;i++){
        all.insert(i);
    }

    for (int i=0;i<M;i++){
        string com;
        cin >> com;
        if (com == "add"){
            int n;
            cin >> n;
            S.insert(n);
        }
        else if (com == "remove"){
            int n;
            cin >> n;
            if (S.count(n)) S.erase(n);
        }
        else if (com == "check"){
            int n;
            cin >> n;
            if (S.count(n)) cout << "1\n";
            else cout << "0\n";
        }
        else if (com == "toggle"){
            int n;
            cin >> n;
            if (S.count(n)) S.erase(n);
            else S.insert(n);
        }
        else if (com == "all"){
            S = all;
        }
        else if (com == "empty"){
            S.clear();
        }
    }


    return 0;
}
