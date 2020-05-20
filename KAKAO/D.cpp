#include <iostream>

const int S = 0;
const int R = 1;
const int P = 2;

using namespace std;

int result(char a, char b){ // 0 : a win, 1 : b win, 2 : tie
    int ret = -1;
    if (a == 'S'){
        if (b == 'S') ret =  2;
        if (b == 'R') ret =  1;
        if (b == 'P') ret =  0;
    }
    else if (a == 'R'){
        if (b == 'S') ret =  0;
        if (b == 'R') ret =  2;
        if (b == 'P') ret =  1;
    }
    else if (a == 'P'){
        if (b == 'S') ret =  1;
        if (b == 'R') ret =  0;
        if (b == 'P') ret =  2;
    }
    return ret;
}

int n, a;
string pre, temp, curr;
int prehand = -1;
int ans = 0;

int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> a;
    cin >> temp;
    for (int i=0;i<a;i++){
        curr += temp[i];
    }
    curr += 'K';
    for (int i=a;i<n-1;i++){
        curr += temp[i];
    }
    while(1){
        pre = "";
        int curr_size = curr.size();
//        cout << curr << endl;
        
        for (int i=0;i<curr_size;i+=2){
            if (i == curr.size() - 1) {
                pre += curr[i];
                continue;
            }
            char left = curr[i], right = curr[i+1];
            if (left != 'K' && right != 'K'){
                int res = result(left, right);
                if (res == 0){ // A win
                    pre += left;
                }
                else if (res == 1){ // B win
                    pre += right;
                }
            }
            else{
                if (left == 'K'){
//                    cout << left << " " << right << endl;
                    pre += 'K';
                    int winning = -1;
                    if (right == 'S') winning = R;
                    else if (right == 'R') winning = P;
                    else if (right == 'P') winning = S;
                    if (winning != -1 && prehand != winning) ans++;
//                    cout << prehand << " " << winning << endl;                     
                    prehand = winning;
                    continue;
                }
                else if (right == 'K'){
//                    cout << left << " " << right << endl;
                    pre += 'K';
                    int winning = -1;
                    if (left == 'S') winning = R;
                    else if (left == 'R') winning = P;
                    else if (left == 'P') winning = S;
                    if (winning != -1 && prehand != winning) {
                        ans++;
                    }
//                    cout << prehand << " " << winning << endl;
                    prehand = winning;
                    continue;
                }
            }
        }
        curr = pre;
        if (curr.size() == 1) {
            break;
        }
    }
    cout << ans-1;

    return 0;
}



