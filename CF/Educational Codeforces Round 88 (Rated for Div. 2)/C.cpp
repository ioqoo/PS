#include <bits/stdc++.h>

const double INF = 987654321.;
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T;
    scanf("%d", &T);
    while(T--){
        double h, c;
        double t;
        scanf("%lf %lf %lf", &h, &c, &t);
        if (h == t) {
            printf("1\n");
            continue;
        }
        else if ((h+c)/2 >= t) {
            printf("2\n");
            continue;
        }
        int lo = 0, hi = 1000000000;
        int mid;
        double diff = h - t;
        int ans = 1;
        while(lo < hi-1){
//            printf("%d %d\n", lo, hi);
            mid = (lo + hi) / 2;
//            printf("%lf\n", ((double)mid*h + ((double)mid-1)*c)/(double)(2*(double)mid-1));
            double curr_diff = abs(((double)mid*h + ((double)mid-1)*c)/(double)(2*(double)mid-1) - t);
            if (curr_diff < diff){
                ans = mid;
                diff = curr_diff;
            }
            else if (curr_diff == diff){
                ans = min(ans, mid);
            }
//            printf("ans : %d\n", ans);
            if ( ((double)mid*h + ((double)mid-1)*c)/(2*(double)mid-1) > t){
                lo = mid;
            }
            else {
                hi = mid;
            }
        }
        printf("%d\n", 2*ans-1);
    }

    return 0;
}



