#include <bits/stdc++.h>
#define MAX 10005
#define ll long long

using namespace std;

typedef struct BigInt{
    int carry;
    int num;
}BI;

BI char_sum(char a, char b, int carry){
    int x = a - '0';
    int y = b - '0';
    return BI{(x + y + carry) / 10 , (x + y + carry) % 10};
}

string BI_sum(string A, string B){
    string ret = B;
    while(A.size() < B.size()){
        A = '0' + A;
    }

    int carry = 0;
    for (int i=A.size()-1;i>=0;i--){
        char x = A[i], y = B[i];
        BI temp = char_sum(x, y, carry);
        char c = temp.num + '0';
        ret[i] = c;
        carry = temp.carry;
    }

    if (carry != 0){
        char c = carry + '0';
        ret = c + ret;
    }

    return ret;

}



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    string a = "0";
    string b = "1";

    if (n == 0) cout << 0;
    else if (n == 1) cout << 1;
    else{
        for (int i=2;i<=n;i++){
            string c = BI_sum(a, b);
            a = b;
            b = c;
        }
        cout << b;
    }

    return 0;
}
