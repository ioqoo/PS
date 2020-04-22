#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <unordered_map>

#define MAX 200005

using namespace std;

int T, F;
int p[MAX];
string A, B;
unordered_map<string, int> mp;

int find(int node){
    if (p[node] < 0) return node;
    
    return p[node] = find(p[node]);
}

void merge(int a, int b){
    int roota = find(a);
    int rootb = find(b);
    if (roota == rootb) return;
    
    p[rootb] += p[roota];
    p[roota] = rootb;
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> T;
    while(T>0){
        T--;
        
        memset(p, -1, sizeof(p));
        mp.clear();
        int num = 0;
        cin >> F;
        for (int i=0;i<F;i++){
            cin >> A >> B;
            if (!mp.count(A)) {
                mp[A] = ++num;
            }
            if (!mp.count(B)) {
                mp[B] = ++num;
            }
            int A_num = mp[A], B_num = mp[B];
            merge(A_num, B_num);
            printf("%d\n", -p[find(A_num)]);
        }
    }

    return 0;
}

