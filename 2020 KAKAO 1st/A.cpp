#include <string>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    vector<char> temp;
    for (int i=0;i<new_id.size();i++){
    	char c = new_id[i];

    	if ('a' <= c && c <= 'z'){
    		temp.push_back(c);
		}
		else if ('A' <= c && c <= 'Z'){
			temp.push_back(c - 'A' + 'a');
		}
		else if ('0' <= c && c <= '9') {
			temp.push_back(c);
		}
		else if (c == '_' || c == '-'){
			temp.push_back(c);
		}
		else if (c == '.'){
			temp.push_back(c);
		}
	}
//	for (auto C: temp){
//		cout << C << endl;
//	}
	
	vector<char> temp2;

    int new_size = temp.size();
    bool flag = false;
    for (int i=0;i<new_size;i++){
    	if (!flag){
    		if (temp[i] == '.'){
    			flag = true;
    			temp2.push_back(temp[i]);
			}
			else{
				temp2.push_back(temp[i]);
			}
		}
		else{
			if (temp[i] == '.') continue;
			else {
				flag = false;
				temp2.push_back(temp[i]);
			}
		}
	}
	
//	for (auto C: temp2){
//		cout << C << endl;
//	}	
	
	vector<char> temp3;
	for (int i=0;i<temp2.size();i++){
		if (i==0 && temp2[i] == '.') continue;
		if (i == temp2.size()-1 && temp2[i] == '.') continue;
		temp3.push_back(temp2[i]);
	}
	
//	for (auto C: temp3){
//		cout << C << endl;
//	}
	
	if (temp3.empty()) temp3.push_back('a');
	
	if (temp3.size() >= 16){
		for (int i=0;i<15;i++){
			if (i == 14 && temp3[i] == '.') continue;
			answer += temp3[i];
		}
	}
	else if (temp3.size() <= 2){
		char k = temp3.back();
		while(temp3.size() < 3){
			temp3.push_back(k);
		}
		for (auto C: temp3){
			answer += C;
		}
	}
	else{
		for (auto C: temp3){
			answer += C;
		}
	}

    
    return answer;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string k = "123_.def";
	cout << solution(k);
	
	return 0;
}

