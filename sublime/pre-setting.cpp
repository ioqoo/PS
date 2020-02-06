#include <iostream>
#include <cstdio>
#include <string>
//#include <cstdlib> // atoi
//#include <cmath>
//#include <cstring> // memset, memcpy
#include <algorithm>
//#include <stack>
//#include <queue>
//#include <deque>
//#include <vector>
//#include <functional>
//#include <map>
//#include <set>
//#include <utility> // pair
//#define ll long long
//#define pii pair<int, int>

using namespace std;

string s, t;
vector<int> pos;

int main(){
	cin >> s >> t;
	int a = 0, b = 0, prev_a = 0;
	pos.push_back(0);
	int s_size = s.size(), t_size = t.size();
	while (a<s_size && b<t_size){
		if (s[a] != t[b]){
			a++;
		}
		else {
			pos.push_back(a-prev_a);
			prev_a = a;
			a++;
			b++;
		}
	}
	int max_val = 0;
	sort(pos.begin(), pos.end());
	for (int i=0;i<pos.size();i++){
		if (max_val < pos[i]) {
			max_val = pos[i];
		}
	}
	printf("%d\n", max_val);
}