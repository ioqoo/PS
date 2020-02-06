#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, k;
vector<int> devices[101];
vector<int> nomore;
int occur_cnt[101];
int order[101];
int tap[101]; // index번째 구멍에 val device가 꽂힘
int where[101]; // index번째 device가 멀티탭 val위치에 꽂힘
int ans;

int main(){
	scanf("%d %d", &n, &k);
	fill(tap, tap+101, -1);
	fill(where, where+101, -1);
	for (int i=1;i<=k;i++){
		int temp;
		scanf("%d", &temp);
		occur_cnt[temp]++;
		order[i] = temp;
	}
	for(int i=1;i<=k;i++){
		int now = order[i];
		if (where[now] == -1){
			bool succ = false;
			for (int j=1;j<=n;j++){
				if (tap[j]==-1){
					tap[j] = now;
					where[now] = j;
					succ = true;
					break;
				}
			}
			if (!succ && i!=k){
				for (int j=i+1;j<=k;j++){
					int discard_device = order[j];

					if (!nomore.empty()){
						int plug_device = nomore.back();
						nomore.pop_back();
						tap[where[plug_device]] = now;
						where[now] = where[plug_device];
						where[plug_device] = -1;
						ans++;
						break;
					}

					if (where[discard_device]!=-1){
						continue;
					}
					else{
						discard_device = order[j-1];
						int plug_pos = where[discard_device];
						tap[plug_pos] = now;
						where[now] = plug_pos;
						where[discard_device] = -1;
						ans++;
						break;
					}
				}
			}
			else if (!succ && i==k){
					ans++;
			}
		}
		occur_cnt[now]--;
		if (occur_cnt[now] == 0){
			nomore.push_back(now);
		}

		printf("now : %d // ans : %d // multi-tap : ", now, ans);
		for (int i=1;i<=n;i++){
			printf("%d ", tap[i]);
		}
		printf("\n");

		printf("index : device, val : pos = ");
		for (int i=1;i<=k;i++){
			printf("%d ", where[i]);
		}
		printf("\n");
		printf("--------------\n");
	}
	printf("%d\n", ans);
}