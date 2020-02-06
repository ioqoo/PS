#include <bits/stdc++.h>
#define MAX 10005
#define ll long long

using namespace std;

int N;
queue<int> q;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i=0;i<N;i++){
        string com;
        cin >> com;
        if (com == "push"){
            int n;
            cin >> n;
            q.push(n);
        }
        else if (com == "pop"){
            if (q.empty()){
                cout << "-1\n";
            }
            else{
                int temp = q.front();
                q.pop();
                cout << temp << "\n";
            }
        }
        else if (com == "size"){
            cout << q.size() << "\n";
        }
        else if (com == "empty"){
            cout << q.empty() << "\n";
        }
        else if (com == "front"){
            if (q.empty()){
                cout << "-1\n";
            }
            else{
                cout << q.front() << "\n";
            }
        }
        else if (com == "back"){
            if (q.empty()){
                cout << "-1\n";
            }
            else{
                cout << q.back() << "\n";
            }
        }
    }

    return 0;
}
