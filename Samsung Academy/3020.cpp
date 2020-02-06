#include <bits/stdc++.h>
#define MAX 100005
#define INF 987654321
#define ll long long

using namespace std;

int N, H;
vector<int> up, down;
int min_val = INF;
vector<int> min_pos;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);

    scanf("%d %d", &N, &H);

    for (int i=0;i<N/2;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        up.push_back(a);
        down.push_back(H-b);
    }

    sort(up.begin(), up.end());
    sort(down.begin(), down.end());

    for (int i=0;i<H;i++){
        int up_break = up.end() - lower_bound(up.begin(), up.end(), i);
        int down_avoid = down.end() - lower_bound(down.begin(), down.end(), i);
        int down_break = N/2 - down_avoid;
        int curr_break = up_break + down_break;
        if (curr_break < min_val){
            min_val = curr_break;
            min_pos.clear();
            min_pos.push_back(i);
        }
        else if (curr_break == min_val){
            min_pos.push_back(i);
        }
    }

    printf("%d %d\n", min_val, min_pos.size());


    return 0;
}
