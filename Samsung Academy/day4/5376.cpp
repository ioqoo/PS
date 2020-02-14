#include <bits/stdc++.h>
#define MAX 10005
#define ll long long

using namespace std;

char alpha[36];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll N;
    ll B;
    cin >> N >> B;
    
    for (int i=0;i<36;i++){
    	if (0<=i && i<=9){
    		alpha[i] = '0'+i;
		}
		else{
			alpha[i] = 'A'+i-10;
		}
	}
    
    string ans = "";
    
    while(N >= B){
    	ll digit = N % B;
    	ans = alpha[digit] + ans;
    	N /= B;
	}
    ans = alpha[N] + ans;
    
    cout << ans;
    


    return 0;
}
