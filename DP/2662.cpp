#include <iostream>
#include <cstring>
#include <stack>

#define MAX 303

using namespace std;

int N, M;
int dp[MAX];
int benefit[22][MAX];
int previ[22][MAX];



int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d %d", &N, &M);
	int a, temp;
	for (int i=1;i<=N;i++){
	    scanf("%d", &a);
	    for (int j=1;j<=M;j++){
	        scanf("%d", &temp);
	        benefit[j][i] = temp;
        }
    }
    for (int j=1;j<=N;j++){
        dp[j] = benefit[1][j];
    }
    for (int j=1;j<=N;j++){
        previ[1][j] = j;
    }
    
    for (int i=2;i<=M;i++){
        for (int j=1;j<=N;j++){
            int curr_max = 0;
            int curr_pos = 0;
            for (int k=0;k<=j;k++){
                if (benefit[i][k] + dp[j-k] > curr_max){
                    curr_max = benefit[i][k] + dp[j-k];
                    curr_pos = k;
                }
            }
            dp[j] = curr_max;
            previ[i][j] = curr_pos;
        }
    }
    
    stack<int> st;
    int T = M;
    int money = N;
    while(T>0){
        st.push(previ[T][money]);
        T--;
        money -= previ[T][money];
    }
    
    printf("%d\n", dp[N]);
    while(!st.empty()){
        printf("%d ", st.top());
        st.pop();
    }

	return 0;
}

