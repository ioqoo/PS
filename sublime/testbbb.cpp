#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		int ans[101] = {0, };
		int arr[101] = {0,};
		bool visited[101] = {0, };

		scanf("%d", &n);
		for (int i=0;i<n;i++){
			scanf("%d", &arr[i]);
		}
		int num[101] = {0, };
		for (int i=1;i<=n;i++){
			num[i] = i-1;
		}


		bool cor = false;
		for (int i=n-1;i>=0;--i){
			int now = arr[i];
			int flag = false;
			if(cor) break;
			for (int j = 1; j <= n; ++j){
			 	if(visited[j]) continue;
			 	if(now == num[j]){
			 		ans[i] = j;
			 		visited[j] = true;
			 		flag = true;
			 		for (int k = j; k<=n; k++)
			 			num[k]-=1;
			 		break;
			 	}
			} 
			if(!flag)
			 	cor = true;
		}

		if(cor)
			cout << "IMPOSSIBLE" << '\n';
		else{
			for (int i = 0; i < n; ++i)
				cout << ans[i] << ' ';
			cout << '\n';
		}
				
			



	}
}