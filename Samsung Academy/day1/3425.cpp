#include <bits/stdc++.h>
#define MAX 10005
#define ll long long
#define MAX 1000000000

using namespace std;

vector<string> coms;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(true){
        string com;
        cin >> com;
        if (com == "QUIT") break;
        string num;
        if (com == "NUM"){
            cin >> num;
            com = com + " " + num;
        }
        if (com == "END"){
            int n;
            cin >> n;
            for (int x=0;x<n;x++){
                stack<ll> st;
                ll v;
                cin >> v;
                st.push(v);
                bool error = false;

                for (string s: coms){
                    string curr_com = s.substr(0, 3);

                    if (curr_com == "NUM"){
                        st.push(stoll(s.substr(4)));
                    }
                    else if (curr_com == "POP"){
                        if (st.empty()){
                            cout << "ERROR\n";
                            error = true;
                            break;
                        }
                        st.pop();
                    }
                    else if (curr_com == "INV"){
                        if (st.empty()){
                            cout << "ERROR\n";
                            error = true;
                            break;
                        }
                        ll top = st.top();
                        st.pop();
                        st.push(top * (-1LL));
                    }
                    else if (curr_com == "DUP"){
                        if (st.empty()){
                            cout << "ERROR\n";
                            error = true;
                            break;
                        }
                        ll top = st.top();
                        st.push(top);
                    }
                    else if (curr_com == "SWP"){
                        if (st.empty()){
                            cout << "ERROR\n";
                            error = true;
                            break;
                        }
                        ll top1 = st.top();
                        st.pop();
                        if (st.empty()){
                            cout << "ERROR\n";
                            error = true;
                            break;
                        }
                        ll top2 = st.top();
                        st.pop();
                        st.push(top1);
                        st.push(top2);
                    }
                    else if (curr_com == "ADD"){
                        if (st.empty()){
                            cout << "ERROR\n";
                            error = true;
                            break;
                        }
                        ll top1 = st.top();
                        st.pop();
                        if (st.empty()){
                            cout << "ERROR\n";
                            error = true;
                            break;
                        }
                        ll top2 = st.top();
                        st.pop();
                        ll result = top1 + top2;
                        if (abs(result) > MAX){
                            error = true;
                            cout << "ERROR\n";
                            break;
                        }
                        st.push(result);
                    }
                    else if (curr_com == "SUB"){
                        if (st.empty()){
                            cout << "ERROR\n";
                            error = true;
                            break;
                        }
                        ll top1 = st.top();
                        st.pop();
                        if (st.empty()){
                            cout << "ERROR\n";
                            error = true;
                            break;
                        }
                        ll top2 = st.top();
                        st.pop();
                        ll result = top2 - top1;
                        if (abs(result) > MAX){
                            error = true;
                            cout << "ERROR\n";
                            break;
                        }
                        st.push(result);
                    }
                    else if (curr_com == "MUL"){
                        if (st.empty()){
                            cout << "ERROR\n";
                            error = true;
                            break;
                        }
                        ll top1 = st.top();
                        st.pop();
                        if (st.empty()){
                            cout << "ERROR\n";
                            error = true;
                            break;
                        }
                        ll top2 = st.top();
                        st.pop();
                        ll result = top2 * top1;
                        if (abs(result) > MAX){
                            error = true;
                            cout << "ERROR\n";
                            break;
                        }
                        st.push(result);
                    }
                    else if (curr_com == "DIV"){
                        if (st.empty()){
                            cout << "ERROR\n";
                            error = true;
                            break;
                        }
                        ll top1 = st.top();
                        st.pop();
                        if (st.empty()){
                            cout << "ERROR\n";
                            error = true;
                            break;
                        }
                        ll top2 = st.top();
                        st.pop();
                        if (top1 == 0LL) {
                            error = true;
                            cout << "ERROR\n";
                            break;
                        }
                        ll result = top2 / top1;
                        if (abs(result) > MAX){
                            error = true;
                            cout << "ERROR\n";
                            break;
                        }
                        st.push(result);
                    }
                    else if (curr_com == "MOD"){
                        if (st.empty()){
                            cout << "ERROR\n";
                            error = true;
                            break;
                        }
                        ll top1 = st.top();
                        st.pop();
                        if (st.empty()){
                            cout << "ERROR\n";
                            error = true;
                            break;
                        }
                        ll top2 = st.top();
                        st.pop();
                        if (top1 == 0LL) {
                            error = true;
                            cout << "ERROR\n";
                            break;
                        }
                        ll result = top2 % top1;
                        if (abs(result) > MAX){
                            error = true;
                            cout << "ERROR\n";
                            break;
                        }
                        st.push(result);
                    }
                }
                if (error) continue;
                if (st.size() != 1){
                    cout << "ERROR\n";
                    continue;
                }
                else{
                    ll ans = st.top();
                    cout << ans << "\n";
                }
            }
            cout << "\n";
            coms.clear();
        }

        coms.push_back(com);
    }

    return 0;

}
