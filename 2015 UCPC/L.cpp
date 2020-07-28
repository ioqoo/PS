#include <bits/stdc++.h>
typedef long long ll;
const ll MOD = 1e9 + 7;
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	scanf("%d", &t);
	while(t--){
		int N;
		scanf("%d", &N);
		vector<int> vt;
		vector<int> origin;
		int ans = 0;
		int two_cnt = 0;
		bool is_pos = true;
		for (int i=0;i<N;i++){
			int temp;
			scanf("%d", &temp);
			origin.push_back(temp);
			if (temp != 0){
				if (temp < 0){
					is_pos ^= 1;
				}
				if (temp == -2){
					two_cnt++;
				}
				else if (temp == 2){
					two_cnt++;
				}
				vt.push_back(temp);
			}
			else{
				if (is_pos) {
					ans = max(ans, two_cnt);
				}
				else{
					int subtract_two = 0;
					for (int i=0;i<vt.size();i++){
						if (vt[i] > 0){
							if (vt[i] == 2){
								subtract_two++;
							}
						}
						else{
							if (vt[i] == -1){
								break;
							}
							else if (vt[i] == -2){
								subtract_two++;
								break;
							}
						}
					}
					
					int subtract_two_2 = 0;
					for (int i=vt.size()-1;i>=0;i--){
						if (vt[i] > 0){
							if (vt[i] == 2){
								subtract_two_2++;
							}
						}
						else{
							if (vt[i] == -1){
								break;
							}
							else if (vt[i] == -2){
								subtract_two_2++;
								break;
							}
						}
					}
					int subtract_two_min = min(subtract_two, subtract_two_2);
					int curr_two_cnt = two_cnt - subtract_two_min;
					
					ans = max(ans, curr_two_cnt);
				}
				
				is_pos = true;
				two_cnt = 0;
				vt.clear();
			}
		}
		
		if (is_pos) {
			ans = max(ans, two_cnt);
		}
		else{
			int subtract_two = 0;
			for (int i=0;i<vt.size();i++){
				if (vt[i] > 0){
					if (vt[i] == 2){
						subtract_two++;
					}
				}
				else{
					if (vt[i] == -1){
						break;
					}
					else if (vt[i] == -2){
						subtract_two++;
						break;
					}
				}
			}
			
			int subtract_two_2 = 0;
			for (int i=vt.size()-1;i>=0;i--){
				if (vt[i] > 0){
					if (vt[i] == 2){
						subtract_two_2++;
					}
				}
				else{
					if (vt[i] == -1){
						break;
					}
					else if (vt[i] == -2){
						subtract_two_2++;
						break;
					}
				}
			}
			int subtract_two_min = min(subtract_two, subtract_two_2);
			int curr_two_cnt = two_cnt - subtract_two_min;
			
			ans = max(ans, curr_two_cnt);
		}
		
		
		if (ans==0){
			bool succ = false;
			for (int i=0;i<N;i++){
				if (origin[i] == 1){
					printf("1\n");
					succ = true;
					break;
				}
				if (i){
					if (origin[i] == -1 && origin[i-1] == -1){
						printf("1\n");
						succ = true;
						break;
					}
				}
			}
			if (!succ){
				printf("0\n");
			}
		}
		else{
			ll ret = 1LL;
			for (int i=0;i<ans;i++){
				ret = (ret*2LL)%MOD;
			}
			printf("%lld\n", ret);
		}

	}
	
	
	return 0;
}


