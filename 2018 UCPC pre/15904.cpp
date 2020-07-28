#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    char word[1005];
    string W;
    while(scanf("%s", word) != EOF){
        W += word;
    }
    
    
    bool succ1 = false, succ2 = false, succ3 = false, succ4 = false;
    for (int i=0;i<W.size();i++){
//        if (i=='\0') break;
        char curr = W[i];
        if (!succ1){
            if (curr == 'U') {
                succ1 = true;
            }
        }
        else{
            if (!succ2){
                if (curr == 'C'){
                    succ2 = true;
                }
            }
            else{
                if (!succ3){
                    if (curr == 'P'){
                        succ3 = true;
                    }
                }
                else{
                    if (!succ4){
                        if (curr == 'C'){
                            succ4 = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    if (succ4) printf("I love UCPC\n");
    else printf("I hate UCPC\n");

    return 0;
}



