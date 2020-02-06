#include <bits/stdc++.h>
#define MAX 10005
#define ll long long

using namespace std;

int N;
stack<int> st;

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
            st.push(n);
        }
        else if (com == "pop"){
            if (st.empty()){
                cout << "-1\n";
            }
            else{
                int temp = st.top();
                st.pop();
                cout << temp << "\n";
            }
        }
        else if (com == "size"){
            cout << st.size() << "\n";
        }
        else if (com == "empty"){
            cout << st.empty() << "\n";
        }
        else if (com == "top"){
            if (st.empty()){
                cout << "-1\n";
            }
            else{
                cout << st.top() << "\n";
            }
        }
    }

    return 0;
}
