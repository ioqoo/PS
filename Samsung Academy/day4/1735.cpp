#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
	if (b==0) return a;
	else return gcd(b, a%b);		
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	int a1, b1, a2, b2;
	scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
	
	int a3 = a1 * b2 + a2 * b1;
	int b3 = b1 * b2;
	int GCD = gcd(a3, b3);
	a3 /= GCD; b3 /= GCD;
	printf("%d %d\n", a3, b3);

	return 0;
}
