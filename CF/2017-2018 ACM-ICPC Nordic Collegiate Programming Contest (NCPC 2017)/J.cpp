#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int l, r;
    scanf("%d %d", &l, &r);
    
    if(l==0 && r==0) {
        printf("Not a moose\n");
        return 0;
    }
    if (l==r){
        printf("Even %d\n", 2*l);
    }
    else{
        printf("Odd %d\n", max(l,r)*2);
    }
    

    return 0;
}



