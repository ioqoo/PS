#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int N;
vector<int> turn;
vector<int> ans;
int curr = 0;
int curr_x, curr_y;

void turn_left(){
	curr = (curr+4-1)%4;
}

void turn_right(){
	curr = (curr+1)%4;
}

int max_up, max_down, max_left, max_right;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	max_right = 1;
	curr_x = 1;
	ans.push_back(1);
	
	scanf("%d", &N);
	for (int i=0;i<N;i++){
		int d, t;
		scanf("%d %d", &d, &t);
		turn.push_back(t);
	}
	
	for (int t: turn){
		if (t == 1) turn_left();
		else if (t == -1) turn_right();
		else break;
		
		if (curr == 0){
			ans.pb(max_right + 1 - curr_x);
			curr_x = max_right+1;
			max_right++;
		}
		else if (curr == 1){
			ans.pb(curr_y - max_down + 1);
			curr_y = max_down-1;
			max_down--;
		}
		else if (curr == 2){
			ans.pb(curr_x - max_left + 1);
			curr_x = max_left - 1;
			max_left--;
		}
		else if (curr == 3){
			ans.pb(max_up + 1 - curr_y);
			curr_y = max_up + 1;
			max_up++;
		}
	}
	
	for (int n: ans){
		printf("%d ", n);
	}
	
	
	return 0;
}


