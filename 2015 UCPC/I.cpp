#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int N;
	cin >> N;
	string YJ_time, YJ_UTC;
	cin >> YJ_time >> YJ_UTC;

	double YJ_UTC_val = stod(YJ_UTC.substr(3, YJ_UTC.size() - 3));
	int YJ_H = stoi(YJ_time.substr(0, 2));
	int YJ_M = stoi(YJ_time.substr(3, 2));
	for (int i=0;i<N;i++){
		string worker_UTC;
		cin >> worker_UTC;
		double worker_UTC_val = stod(worker_UTC.substr(3, worker_UTC.size() - 3));
		double diff = worker_UTC_val - YJ_UTC_val;
		double frac = diff - (int)diff;
		int integer = diff - frac;
//		cout << integer << " " << frac << endl;
		
		int ans_H = YJ_H + integer;
		int ans_M = YJ_M + 60*frac;
		
		if (ans_M < 0){
			ans_H--;
			ans_M += 60;
		}
		if (ans_M >= 60){
			ans_H++;
			ans_M %= 60;
		}
		ans_H = (ans_H+24)%24;
		
		cout.fill('0');
		cout.width(2);
		cout << ans_H << ":";
		cout.fill('0');
		cout.width(2);
		cout << ans_M << "\n";
	}
	
	return 0;
}


