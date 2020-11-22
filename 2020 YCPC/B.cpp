#include <bits/stdc++.h>

using namespace std;

char grid[1005][1005];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;
	cin >> N;
	
	bool find_head = false;
	bool find_arm = false;
	int head_i, head_j;
	int first_arm, last_arm;
	for (int i=0;i<N;i++){
		string row;
		cin >> row;
		for (int j=0;j<N;j++){
			grid[i][j] = row[j];
		}
	}
	
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			if (!find_head && grid[i][j] == '*'){
				find_head = true;
				head_i = i;
				head_j = j;
				break;
			}
		}
		if (find_head) break;
	}
	
	int heart_i = head_i + 1, heart_j = head_j;
	
	int left_arm_len;
	for (int j=1;heart_j-j >= 0;j++){
		if (grid[heart_i][heart_j - j] == '_'){
			left_arm_len = j-1;
			break;
		}
		if (heart_j - j == 0) left_arm_len = j;
	}
	int right_arm_len;
	for (int j=1;heart_j+j < N;j++){
		if (grid[heart_i][heart_j + j] == '_'){
			right_arm_len = j-1;
			break;
		}
		if (heart_j + j == N-1) right_arm_len = j;
	}
	int wrist_len;
	int wrist_end_i;
	for (int i=1;heart_i+i < N;i++){
		if (grid[heart_i + i][heart_j] == '_'){
			wrist_len = i-1;
			wrist_end_i = heart_i+i;
			break;
		}
		if (heart_i + i == N-1) wrist_len == i;
	}
	
	int left_leg_len;
	for (int i=0;wrist_end_i+i<N;i++){
		if (grid[wrist_end_i+i][heart_j-1] == '_'){
			left_leg_len = i;
			break;
		}
		if (wrist_end_i+i== N-1) left_leg_len = i+1;
	}
	int right_leg_len;
	for (int i=0;wrist_end_i+i<N;i++){
		if (grid[wrist_end_i+i][heart_j+1] == '_'){
			right_leg_len = i;
			break;
		}
		if (wrist_end_i+i == N-1) right_leg_len = i+1;
	}
	cout << heart_i + 1 << " " << heart_j + 1 << "\n";
	cout << left_arm_len << " " << right_arm_len<< " " << wrist_len << " " << left_leg_len << " " << right_leg_len << "\n";
	
	return 0;
}


