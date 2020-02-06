#include <iostream>
//#include <cstdio>
#include <vector>

using namespace std;

//A : 65, Z : 90, ' . '' : 46

int N;
vector<int> graph[26];

void pre_trav(int node){
	int lc = graph[node][0];
	int rc = graph[node][1];
	cout << (char)(node+65);
	if (lc!=46-65) pre_trav(lc);
	if (rc!=46-65) pre_trav(rc);
}

void in_trav(int node){
	int lc = graph[node][0];
	int rc = graph[node][1];
	if (lc!=46-65) in_trav(lc);
	cout << (char)(node+65);
	if (rc!=46-65) in_trav(rc);
}

void post_trav(int node){
	int lc = graph[node][0];
	int rc = graph[node][1];
	if (lc!=46-65) post_trav(lc);
	if (rc!=46-65) post_trav(rc);	
	cout << (char)(node+65);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	

	cin >> N;
	for (int X=0;X<N;X++){
		char a, b, c;
		cin >> a >> b >> c;
		graph[a-65].push_back(b-65);
		graph[a-65].push_back(c-65);
	}
	pre_trav(0);
	cout << "\n";
	in_trav(0);
	cout << "\n";
	post_trav(0);	
}