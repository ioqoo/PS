#include <bits/stdc++.h>

using namespace std;

set<string> dp;
// 0 : 빈거 , 1 : 검은색, 2 : 흰색 
int w_x, w_y;
int ans;

bool good(int x1, int y1, int x2, int y2){
	if(x1>=0 && y1>=0 && x1<4 && y1<4 && x2>=0 && y2>=0 && x2<4 && y2<4) return true;
	return false;
}
bool ok(string state, int x, int y, char curr){
	int x1, y1, x2, y2;
	// case 1 ( 맨앞) 
	x1 = x;
	y1 = y+1;
	x2 = x;
	y2 = y+2;
	if(good(x1,y1,x2,y2)) {
		if(state[x1 + 4*y1]==curr && state[x2 + 4*y2]==curr) return true;	
	}
	x1 = x-1;
	y1 = y;
	x2 = x-2;
	y2 = y;
	if(good(x1,y1,x2,y2)) {
		if(state[x1 + 4*y1]==curr && state[x2 + 4*y2]==curr) return true;	
	}
	x1 = x-1;
	y1 = y+1;
	x2 = x-2;
	y2 = y+2;
	if(good(x1,y1,x2,y2)) {
		if(state[x1 + 4*y1]==curr && state[x2 + 4*y2]==curr) return true;	
	}
	x1 = x+1;
	y1 = y+1;
	x2 = x+2;
	y2 = y+2;
	if(good(x1,y1,x2,y2)) {
		if(state[x1 + 4*y1]==curr && state[x2 + 4*y2]==curr) return true;	
	}
	
	//case 2 (중간)
	x1 = x;
	y1 = y-1;
	x2 = x;
	y2 = y+1;
	if(good(x1,y1,x2,y2)) {
		if(state[x1 + 4*y1]==curr && state[x2 + 4*y2]==curr) return true;	
	}
	x1 = x-1;
	y1 = y;
	x2 = x+1;
	y2 = y;
	if(good(x1,y1,x2,y2)) {
		if(state[x1 + 4*y1]==curr && state[x2 + 4*y2]==curr) return true;	
	}
	
	x1 = x+1;
	y1 = y-1;
	x2 = x-1;
	y2 = y+1;
	if(good(x1,y1,x2,y2)) {
		if(state[x1 + 4*y1]==curr && state[x2 + 4*y2]==curr) return true;	
	}
	x1 = x-1;
	y1 = y-1;
	x2 = x+1;
	y2 = y+1;
	if(good(x1,y1,x2,y2)) {
		if(state[x1 + 4*y1]==curr && state[x2 + 4*y2]==curr) return true;	
	}
	
	// case 3 ( 마지막 )
	x1 = x;
	y1 = y-1;
	x2 = x;
	y2 = y-2;
	if(good(x1,y1,x2,y2)) {
		if(state[x1 + 4*y1]==curr && state[x2 + 4*y2]==curr) return true;	
	}
	x1 = x+1;
	y1 = y;
	x2 = x+2;
	y2 = y;
	if(good(x1,y1,x2,y2)) {
		if(state[x1 + 4*y1]==curr && state[x2 + 4*y2]==curr) return true;	
	}
	x1 = x+1;
	y1 = y-1;
	x2 = x+2;
	y2 = y-2;
	if(good(x1,y1,x2,y2)) {
		if(state[x1 + 4*y1]==curr && state[x2 + 4*y2]==curr) return true;	
	}
	x1 = x-1;
	y1 = y-1;
	x2 = x-2;
	y2 = y-2;
	if(good(x1,y1,x2,y2)) {
		if(state[x1 + 4*y1]==curr && state[x2 + 4*y2]==curr) return true;	
	}
	
	return false;
}

void make_dp(string state){
	if(dp.count(state)) return;
	dp.insert(state);

	bool white = false; // 현재 흰색 차례인가. 
	if(state.back()=='W') white = true; 
	 
	int n_x, n_y;
	bool go = false;
	// 0 col
	for(int i=0; i<4;++i){
		if(state[i]=='0'){
			n_x = i;
			n_y = 0;
			go = true;
			break;
		}
	}
	if(go){
		if(n_x == w_x && n_y == w_y){
			if(white && ok(state, n_x, n_y, '2')) ans++;
		}
		else{
			string temp = state;
			if(white && !ok(state, n_x, n_y, '2')){
				temp[n_x + 4*n_y] = '2';
				temp.back() = 'B';
				make_dp(temp);
			}
			if(!white && !ok(state, n_x, n_y, '1')){
				temp[n_x + 4*n_y] = '1';
				temp.back() = 'W';
				make_dp(temp);
			}
		}
	}
	go = false;
	
	// 1 col
	for(int i=4; i<8;++i){
		if(state[i]=='0'){
			n_x = i%4;
			n_y = 1;
			go = true;
			break;
		}
	}
	if(go){
		if(n_x == w_x && n_y == w_y){
			if(white && ok(state, n_x, n_y, '2')) ans++;
		}
		else{
			string temp = state;
			if(white && !ok(state, n_x, n_y, '2')){
				temp[n_x + 4*n_y] = '2';
				temp.back() = 'B';
				make_dp(temp);
			}
			if(!white && !ok(state, n_x, n_y, '1')){
				temp[n_x + 4*n_y] = '1';
				temp.back() = 'W';
				make_dp(temp);
			}
		}
	}
	go = false;
	
	// 2 col
	for(int i=8; i<12;++i){
		if(state[i]=='0'){
			n_x = i%4;
			n_y = 2;
			go = true;
			break;
		}
	}
	if(go){
		if(n_x == w_x && n_y == w_y){
			if(white && ok(state, n_x, n_y, '2')) ans++;
		}
		else{
			string temp = state;
			if(white && !ok(state, n_x, n_y, '2')){
				temp[n_x + 4*n_y] = '2';
				temp.back() = 'B';
				make_dp(temp);
			}
			if(!white && !ok(state, n_x, n_y, '1')){
				temp[n_x + 4*n_y] = '1';
				temp.back() = 'W';
				make_dp(temp);
			}
		}
	}
	go = false;
	
	// 3 col
	for(int i=12; i<16;++i){
		if(state[i]=='0'){
			n_x = i%4;
			n_y = 3;
			go = true;
			break;
		}
	}
	if(go){
		if(n_x == w_x && n_y == w_y){
			if(white && ok(state, n_x, n_y, '2')) ans++;
		}
		else{
			string temp = state;
			if(white && !ok(state, n_x, n_y, '2')){
				temp[n_x + 4*n_y] = '2';
				temp.back() = 'B';
				make_dp(temp);
			}
			if(!white && !ok(state, n_x, n_y, '1')){
				temp[n_x + 4*n_y] = '1';
				temp.back() = 'W';
				make_dp(temp);
			
			}
		}
	}
	
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str = "0000000000000000W";	
	int y;
	cin >> y;
	str[4*(y-1)] = '1';
	cin >> w_x >> w_y;
	w_x--;
	w_y--;
	make_dp(str);
	
	cout << ans << '\n';
	
	return 0;
}


