#include <bits/stdc++.h>

using namespace std;

// FUCKING TAXI 
// 연료통 : A , 처음엔 full
// 이동한 거리 당 금액 : B , 요금 : 이동거리 X B
// 승차 정원 : 3
// 1 갤런당 갈 수 있는 거리 : C 마일
// 주유소 : 3 곳
// 가득 채울 만큼 돈이 있으면 가득 채우고, 이 때는 floor
// 아니면 있는 돈 전부 지불해서 연료 채움.
// 주유소가 목적지인 승객이 있으면 승객이 먼저 내리면서 요금 지불 후 연료
// 출발 : Taxi Garage, 종료 때에도 여기, 승객도 없어야 함 
// 지점 개수 : N
// 문장 개수 : K
struct person{
	int target, meter;
};

struct P{
	int x, y;
};

int A, B, C, N, K;
int garage_num;
map<string, int> spot;
map<int, int> station;
// station[i] : i번 spot은 주유소이고 그때의 기름값 p 
vector<person> passenger;



int get_dist(P A, P B){
	return abs(A.x - B.x) + abs(A.y - B.y);
}

P pos[105]; // pos[i] : i번 spot의 position (x, y) 

int main(){
	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	#endif

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> A >> B >> C; // 연료통, 거리 당 금액, 갤런 당 거리
	cin >> N;
	string temp;
	for (int i=0;i<N;i++){ // spot 입력
		string curr = "";
		int x, y;
		while(true){
			cin >> temp;
			if (0 <= temp[0] - '0' && temp[0] - '0' <= 9){
				x = stoi(temp);
				break;
			}
			curr += temp + " ";
		}
		cin >> y;
		pos[i] = {x, y};
		curr = curr.substr(0, curr.size()-1);
		if (curr == "Taxi Garage"){
			garage_num = i;
		}
		spot[curr] = i;
	}
	for (int i=0;i<3;i++){
		string curr = "";
		int p;
		while(true){
			cin >> temp;
			if (0 <= temp[0] - '0' && temp[0] - '0' <= 9){
				p = stoi(temp);
				break;
			}
			curr += temp + " ";
		}
		curr = curr.substr(0, curr.size()-1);
		station[spot[curr]] = p;
	}
	cin >> K;
	
	getline(cin, temp); // dummy
	const string PICKUP = "Pickup a passenger going to ";
	
	P curr_pos = pos[garage_num];
	double curr_fuel = A;
	int money = 0;
	
	for (int i=0;i<K;i++){
		string line;
		getline(cin, line);
		if (line[0] == 'G'){ // Go to
			string target = line.substr(6, line.size() - 7);
			int next_num = spot[target];
			int dist = get_dist(curr_pos, pos[next_num]);
			double fuel_cost = (double)dist / (double)C;
			if (fuel_cost - curr_fuel > 0){
				cout << "OUT OF GAS\n";
				return 0;
			}			
			vector<person> remain;
			for (auto p: passenger){
				p.meter += dist;
				if (p.target != next_num){
					remain.push_back(p);
				}
				else{
					money += p.meter * B;
				}
			}
			passenger = remain;
			
			curr_fuel -= fuel_cost;
			
			if (station.count(next_num)){ // next target is gas station
				int cost = station[next_num];
				int need_money_full_charge = (int)floor((A - curr_fuel) * (double)cost + 1e-6);
//				cout << "next_num : " << next_num << " / need : " << need_money_full_charge << endl;
				if (money > 0){
					if (money >= need_money_full_charge){ // gas full
						money -= need_money_full_charge;
						curr_fuel = A;
					}
					else{
						curr_fuel += (double)money / (double)cost;
						money = 0;
					}
				}
			}
			curr_pos = pos[next_num];
		}
		else if (line[0] == 'P'){ // Pickup a passenger going to
			string target = line.substr(PICKUP.size(), line.size() - PICKUP.size() - 1);
			int next_num = spot[target];
			if (passenger.size() == 3){
				cout << "CAPACITY FULL\n";
				return 0;
			}
			passenger.push_back({next_num, 0});			
		}
//		cout << curr_fuel << " " << money << endl;
	}
	if (( curr_pos.x != pos[garage_num].x) || (curr_pos.y != pos[garage_num].y)){
		cout << "NOT IN GARAGE\n";
		return 0;
	}
	if (passenger.size() != 0){
		cout << "REMAINING PASSENGER\n";
		return 0;
	}
	cout << money;
	
	
	return 0;
}


