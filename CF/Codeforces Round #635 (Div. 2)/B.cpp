#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

#define pii pair<int, int>

using namespace std;

int T;
int x, n, m;

typedef struct MY{
    int x, n, m;
}my;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &x, &n, &m);
        
        while ( (n>0 || m>0) && x>0 ){
            if (x >= 20 && n > 0) {
                n--;
                x /= 2;
                x += 10;
            }
            else if (m > 0){
                x -= m * 10;
                m = 0;
            }
        }
        
        if (x<=0) printf("YES\n");
        else printf("NO\n");
        
    }

    return 0;
}



