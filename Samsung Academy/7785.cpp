#include <bits/stdc++.h>
#define MAX 10005
#define ll long long

using namespace std;

int n;
set<string> s;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        string name, stat;
        cin >> name >> stat;
        if (stat == "enter") s.insert(name);
        else s.erase(name);
    }
    for (set<string>::reverse_iterator riter=s.rbegin(); riter != s.rend(); ++riter){
        cout << *riter << "\n";
    }


    return 0;
}
