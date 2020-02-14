#include <bits/stdc++.h>
#define MAX 10005
#define ll long long

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    string N;
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    int total_sum = 0;
    
    bool have_zero = false;
    for (auto n: N){
    	if (n == '0') have_zero = true;
    	else total_sum += n - '0';
	}
	if (total_sum % 3 || !have_zero) {
		cout << -1 << "\n";
		return 0;
	}
	sort(N.begin(), N.end(), greater<char>());
	cout << N;
    
    


    return 0;
}
