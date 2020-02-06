#include <bits/stdc++.h>
#define MAX 10005
#define ll long long

using namespace std;

int N;
char temp[31];
map<string, double> mp;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);


    string temp;
    while(getline(cin, temp)){
        N++;
        mp[temp]++;
    }

    cout << fixed;
    cout.precision(4);
    for (auto it=mp.begin();it!=mp.end();it++){
        string name = it->first;
        double cnt = it->second;
        double per = cnt / N * 100.0;
        cout << name << " " << per << "\n";
    }

    return 0;
}
