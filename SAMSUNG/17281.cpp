#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N;
int hitter[50][9];
int ans;

void bt(vector<int> pre_order){
    if (pre_order.size() < 8) {
        for (int i=1;i<9;i++){
            if (!count(pre_order.begin(), pre_order.end(), i)){
                pre_order.push_back(i);
                bt(pre_order);
                pre_order.pop_back();
            }
        }
        return;
    }
    vector<int> order;
    for (int i=0;i<3;i++){
        order.push_back(pre_order[i]);
    }
    order.push_back(0);
    for (int i=3;i<8;i++){
        order.push_back(pre_order[i]);
    }

    int curr_max = 0;
    int last_hitter = 0;
    for (int inn = 0; inn < N; inn++){
        bool runner[4] = {0, 0, 0, 0};
        int out = 0;
        while(out < 3){
            int curr_hitter = hitter[inn][order[last_hitter]];
            switch(curr_hitter){
                case 1:
                    if (runner[3]) curr_max++;
                    runner[3] = runner[2];
                    runner[2] = runner[1];
                    runner[1] = true;
                    break;
                case 2:
                    if (runner[3]) curr_max++;
                    if (runner[2]) curr_max++;
                    runner[3] = runner[1];
                    runner[2] = true;
                    runner[1] = false;
                    break;
                case 3:
                    if (runner[3]) curr_max++;
                    if (runner[2]) curr_max++;
                    if (runner[1]) curr_max++;
                    runner[3] = true;
                    runner[2] = false;
                    runner[1] = false;
                    break;
                case 4:
                    for(int i=1;i<=3;i++){
                        if (runner[i]) curr_max++;
                        runner[i] = false;
                    }
                    curr_max++;
                    break;
                case 0:
                    out++;
                    break;
            }
            last_hitter = (last_hitter + 1) % 9;
        }
    }
    ans = max(ans, curr_max);
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &N);
    for (int i=0;i<N;i++){
        for (int j=0;j<9;j++){
            scanf("%d", &hitter[i][j]);
        }
    }
    for (int i=1;i<9;i++){
        vector<int> ch;
        ch.push_back(i);
        bt(ch);
        ch.pop_back();
    }

    printf("%d\n", ans);
}
