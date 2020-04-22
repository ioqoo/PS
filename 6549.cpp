#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define ll long long
#define MAX 987654321

using namespace std;

int N;
ll H[100005]; 

ll histogram(int a, int b){ // [a, b) ªÁ¿Ã
	if (a==b) return 0;
	if (a==b-1) return H[a];

	int mid = (a+b)/2;
	ll result = max(histogram(a, mid), histogram(mid, b));

	int l = mid, r = mid;
	ll h=H[mid];
	ll w = 1LL;
	while (r-l < b-a-1) {
		int p = l>a ? min(h, H[l-1]) : -1;
		int q = r<b-1 ? min(h, H[r+1]) : -1;
		if (p>=q) {
			h = p;
			l--;
		}
		else {
			h = q;
			r++;
		}
		w++;
		result = max(result, w*h);
	}
	return result;
}

int main(){
//    freopen("input.txt", "r", stdin);
    while(true){
        scanf("%d", &N);
        if (N==0) break;
        memset(H, 0, sizeof(H));
        for (int i=0;i<N;i++){
		  scanf("%lld", &H[i]);
	    }
        printf("%lld\n", histogram(0,N));
    }    
	
	

		
}
