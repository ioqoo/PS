#include <iostream>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    int a, b;
    scanf("%d %d", &a, &b);
    int ans = 0;
    int first = -1;
    bool succ = false;
    for (int i=1;i*i<=b;i++){
        if (a <= i*i && i*i <= b) {
            ans += i*i;
            if (!succ){
                succ = true;
                first = i*i;
            }
        }
    }
    if (first == -1) printf("-1\n");
    else printf("%d\n%d\n", ans, first);

    return 0;
}



