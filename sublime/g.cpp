#include <bits/stdc++.h>

using namespace std;

int order[110];
int gate[110];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=1;i<=n;i++){
    	scanf("%d", &order[i]);
    }
    for (int i=1;i<=n;i++){
    	bool succ = false;
    	for (int j=1;j<=k;j++){
    		if (gate[j] == 0){
    			gate[j] = order[i];
    			succ = true;
    			break;
    		}
    		else {
    			if (gate[j] < order[i]){
    				gate[j] = order[i];
    				succ = true;
    				break;
    			}
    		}
    	}
    	if (!succ) {
    		printf("NO");
    		return 0;
    	}
    }
    printf("YES");
}