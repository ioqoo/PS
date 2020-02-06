#include <iostream>
//#include <cstdio>
//#include <set>
#include <map>
//#include <pair>
#include <string>

using namespace std;

int N, M;
map<int, string> book_num_key;
map<string, int> book_name_key;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	map<string, int> book_name_key;
	map<int, string> book_num_key;

	cin >> N >> M;

	for (int i=1;i<=N;i++){
		string poke;
		cin >> poke;
		book_name_key[poke] = i;
		book_num_key[i] = poke;
	}

	for (int X=0;X<M;X++){
		string prob;
		cin >> prob;
		if (isdigit(prob[0])) {
			int n = atoi(prob.c_str());
			cout << book_num_key[n] << "\n";
		}
		else {
			cout << book_name_key[prob] << "\n";
		}
	}

}