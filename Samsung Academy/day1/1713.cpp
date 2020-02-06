#include <bits/stdc++.h>
#define MAX 20005

int rec[101];
int T[101];
int N, R;
int cnt;

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &N, &R);
    for (int t=1;t<=R;t++){
        int curr;
        scanf("%d", &curr);
        int curr_cnt = 0;
        for (int n=1;n<=100;n++){
            if (rec[n]) curr_cnt++;
        }
        cnt = curr_cnt;
        if (cnt < N) {
            if (rec[curr]){
                rec[curr]++;
            }
            else{
                rec[curr] = 1;
                T[curr] = t;
            }
        }
        else if (rec[curr]) {
            rec[curr]++;
        }
        else{
            int min_val = MAX;
            vector<int> min_pos;
            for (int i=1;i<=100;i++){
                if (rec[i] != 0 && rec[i] < min_val){
                    min_val = rec[i];
                    min_pos.clear();
                    min_pos.push_back(i);
                }
                else if (rec[i] != 0 && rec[i] == min_val){
                    min_pos.push_back(i);
                }
            }
            if (min_pos.size() == 1){
                rec[min_pos[0]] = 0;
                T[min_pos[0]] = 0;
                rec[curr] = 1;
                T[curr] = t;
            }
            else{
                int min_time = MAX;
                int min_p = -1;
                for (int pos: min_pos){
                    if (T[pos] < min_time){
                        min_time = T[pos];
                        min_p = pos;
                    }
                }
                rec[min_p] = 0;
                T[min_p] = 0;
                rec[curr] = 1;
                T[curr] = t;
            }
        }

//        printf(" REC : ");
//        for (int i=1;i<=9;i++){
//            printf("%d ", rec[i]);
//        }
//        printf("\n");
//        printf("TIME : ");
//        for (int i=1;i<=9;i++){
//            printf("%d ", T[i]);
//        }
//        printf("\n\n");
    }

    for (int i=1;i<=100;i++){
        if (rec[i]) {
            printf("%d ", i);
        }
    }

    return 0;

}
