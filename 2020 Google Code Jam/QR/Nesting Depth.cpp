#include <iostream>

using namespace std;

int T;
int remain_l;
string row;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> T;
    for (int t=1;t<=T;t++){
        cout << "Case #" << t << ": ";
        cin >> row;
        remain_l = 0;
        for (char c: row){
            int curr = c - '0';
            if (remain_l < curr){
                while(remain_l < curr){
                    cout << "(";
                    remain_l++;
                }
            }
            else if (remain_l > curr){
                while(remain_l > curr){
                    cout << ")";
                    remain_l--;
                }
            }
            cout << curr;
        }
        while(remain_l > 0){
            cout << ")";
            remain_l--;
        }
        cout << "\n";
    }

    return 0;
}

