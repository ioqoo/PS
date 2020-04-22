#include <iostream>

using namespace std;

int T, a, b, c, d;
int x, y, z;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        printf("%d %d %d\n", b, c, c);
        
    }

    return 0;
}



