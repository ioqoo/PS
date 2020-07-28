#include <bits/stdc++.h>

using namespace std;

string A, B;
set<unordered_map<char, int>> Set;

bool find(int len){
    Set.clear();
    unordered_map<char, int> temp;
    for (int i=0;i<len;i++){
        char curr = A[i];
        temp[curr]++;
    }
//    Set.insert(temp);
//    for (int i=len;i<A.size();i++){
//        char front = A[i-len];
//        char curr = A[i];
//        temp[front]--;
//        temp[curr]++;
//        Set.insert(temp);
//    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> A >> B;
    if (A.size() < B.size()) swap(A, B);
    
    unordered_map<char, int> AA;
    string ttt = "abcaa";
    for (char c: ttt){
        AA[c]++;
    }
    

    return 0;
}



