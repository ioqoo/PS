#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    scanf("%d", &t);
    while(t--){
        int N;
        scanf("%d", &N);
//        vector<int> arr;
        bool chk[200005] = {0,};
        for (int i=1;i<=N;i++){
            int temp;
            scanf("%d", &temp);
            if (i == temp) chk[i] = true;
        }
        int firstneg_pos = -1, lastneg_pos = -1;
        for (int i=1;i<=N;i++){
            if (!chk[i]) {
                firstneg_pos = i;
                break;
            }
        }
        for (int i=N;i>=1;i--){
            if (!chk[i]){
                lastneg_pos = i;
                break;
            }
        }
        if (firstneg_pos == -1 && lastneg_pos == -1){
            printf("0\n");
            continue;
        }
        bool true_ing = false;
        int cnt = 0;
        for (int i=firstneg_pos+1;i<=lastneg_pos-1;i++){
            if (chk[i]){
                if (!true_ing){
                    cnt++;
                    true_ing = true;
                }
            }
            else{
                if (true_ing){
                    true_ing = false;
                }
            }
        }
        printf("%d\n", cnt+1);
    }
    

    return 0;
}



