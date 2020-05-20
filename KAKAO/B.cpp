#include <bits/stdc++.h>

const int MAX = 100;

using namespace std;

int n, m;
vector<int> quant; // m
vector<double> price;

double Round(double x, int d){
	return ( floor((x) * pow(float(10), d) + 0.5f ) / pow(float(10), d));
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    scanf("%d %d", &n, &m);
    int temp;
    for (int i=0;i<m;i++){
        scanf("%d", &temp);
        quant.push_back(temp);
    }
    scanf("%d", &m);
    int nonzerocnt = 0;
    double nonzeroval = 0;
    double ttemp;
    for (int i=0;i<m;i++){
        scanf("%lf", &ttemp);
        if (ttemp > 0) {
            nonzerocnt++;
            nonzeroval = ttemp;
        }
        price.push_back(ttemp);
    }
    
    if (nonzerocnt == 1) {
        printf("%.2lf\n", nonzeroval);
        return 0;
    }
    
    int a = -1, b = -1;
    if (lower_bound(quant.begin(), quant.end(), n) == quant.end()){
        for (int i=m-1;i>=0;i--){
            if (b == -1){
                if (price[i] > 0){
                    b = i;
                }
            }
            else{
                if (price[i] > 0){
                    a = i;
                    break;
                }
            }
        }

        printf("%.2lf\n", Round(price[b] + (double)(n-quant[b]) * (price[b] - price[a]) / (double)(quant[b]-quant[a]), 2));
    }
    else if (lower_bound(quant.begin(), quant.end(), n) == quant.begin()){
        for (int i=0;i<m;i++){
            if (a == -1){
                if (price[i] > 0){
                    a = i;
                }
            }
            else{
                if (price[i] > 0){
                    b = i;
                    break;
                }
            }
        }
        printf("%.2lf\n", Round(price[a] - (double)(quant[a] - n) * ( price[b] - price[a] ) / (double)(quant[b] - quant[a]), 2));
    }
    
    else{
        int pos = lower_bound(quant.begin(), quant.end(), n) - quant.begin();
        if (n == quant[pos]){
            if (price[pos] > 0){
                printf("%.2lf\n", price[pos]);
                return 0;
            }
        }
        
        for (int i=pos-1;i>=0;i--){
            if (price[i] > 0) {
                a = i;
                break;
            }
        }
        for (int i=pos;i<m;i++){
            if (price[i] > 0){
                b = i;
                break;
            }
        }
        printf("%.2lf\n", Round(price[a] - (price[a] - price[b]) * (double)(n - quant[a]) / (double)(quant[b] - quant[a]), 2));
    }

    return 0;
}



