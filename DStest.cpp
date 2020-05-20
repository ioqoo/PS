#include <iostream>

using namespace std;

void abc(int N){
    int r = N%2;
    printf("*");
    if (N >= 2){
        abc(N/2);
    }
    printf("%d", r);
    return;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    abc(78);

    return 0;
}



