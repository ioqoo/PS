#include <bits/stdc++.h>

using namespace std;

int intensity(int r, int g, int b){
    return 2126*r + 7152*g + 722*b;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    int r, g, b;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> r >> g >> b;
            int temp = intensity(r, g, b);
            if (0<=temp && temp< 510000){
                cout << "#";
            }
            else if (510000<=temp && temp<1020000){
                cout << "o";
            }
            else if (1020000 <= temp && temp < 1530000){
                cout << "+";
            }
            else if (1530000 <= temp && temp < 2040000){
                cout << "-";
            }
            else {
                cout << ".";
            }
        }
        if (i != N-1) cout << "\n";
    }
    

    return 0;
}



