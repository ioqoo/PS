#include <bits/stdc++.h>

#define pds pair<double, string>
const int MAX = 505;
using namespace std;

int N;
double dp[MAX];
string namelist[MAX];
vector<pds> vt;
vector<string> arr[MAX];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N;
    string name;
    double a, b;
    for (int i=0;i<N;i++){
        cin >> name >> a >> b;
        dp[i] = a;
        arr[i].push_back(name);
        namelist[i] = name;
        vt.push_back({b, name});
    }
    
    sort(vt.begin(), vt.end());
    
    
    for(int i=0;i<N;i++){
        int cnt=0;
        for(auto it: vt){
            if(cnt==3) break;
            if(it.second == namelist[i]) continue;
            dp[i] += it.first;
            arr[i].push_back(it.second);
            cnt++;
        }
    }  
    
    double ans = 19867654321.0;
    int idx = 0;
    for(int i=0; i<N; ++i){
       if(ans > dp[i]){
           ans = dp[i];
           idx = i;
       } 
    } 
       
    cout << ans << '\n';
    for(auto it: arr[idx]) cout << it << '\n';
    

    return 0;
}



