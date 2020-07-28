#include <bits/stdc++.h>

#define pii pair<int, int>
using namespace std;

struct Point{
    double x, y;
};

double get_dist(Point A, Point B){
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}

int N;
vector<Point> P;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        double x, y;
        scanf("%lf %lf", &x, &y);
        P.push_back({x, y});
    }
    
    auto ans_point = P[0];
    double min_length = 1e7;
    
    for (int i=0;i<N;i++){
        double curr_max = -1;
        for (int j=0;j<N;j++){
            if (i==j) continue;
            double curr_dist = get_dist(P[i], P[j]);
            if (curr_dist - curr_max > 1e-9){
                curr_max = curr_dist;
            }
        }
        if (min_length - curr_max > 1e-9){
            ans_point = P[i];
            min_length = curr_max;
        }
    }
    printf("%.9lf %.9lf\n", ans_point.x, ans_point.y);


    return 0;
}



