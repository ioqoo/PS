#include <bits/stdc++.h>

using namespace std;
const int dmax = 1<<23;

int K, S, edpoint, maxi;
int arr[10000000];
int seg[dmax];

void update(int x, int diff){
    seg[x] = diff;
    while(x/2>=1){
        x/=2;
        seg[x] = max(seg[2*x], seg[2*x+1]);
    }
}

long long ans;

void makeans(int curr, int temp){
    if(curr>edpoint) return;
    if(curr!=1){
        int num = seg[curr]+temp;
        ans += maxi - num;
        temp += maxi - num;
    }    
    
    makeans(2*curr, temp);
    makeans(2*curr+1, temp);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> K;
    S = pow(2,K);
    edpoint = S*2-1;
    
    for(int i = 2; i<=edpoint; ++i){
        cin >> arr[i];
        ans += arr[i];
        arr[i] += arr[i/2];
        if(i>=S){
            maxi = max(maxi, arr[i]);
            update(i, arr[i]);
        }
    }
    
    makeans(1,0);
    
    cout << ans << '\n';

    return 0;
}



