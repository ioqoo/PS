#include <bits/stdc++.h>
#define MAX 10005
#define ll long long
#define MOD 10007LL

using namespace std;

int n, k;
vector<string> nums;
set<string> s;

void perm(int pos, vector<int> ch){
	int ch_size = ch.size();
	if (ch_size == k){
		string ret = "";
		for (int i: ch){
			ret = ret + nums[i];
		}
		if (!s.count(ret)) s.insert(ret);
//		cout << ret << endl;
		return;
	}
	
	for (int j=0;j<n;j++){
		if (find(ch.begin(), ch.end(), j) == ch.end()){
			ch.push_back(j);
			perm(j, ch);
			ch.pop_back();
		}
	}
	return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
    cin >> n >> k;
    for (int i=0;i<n;i++){
    	string temp;
    	cin >> temp;
    	nums.push_back(temp);
	}
	
	for (int i=0;i<n;i++){
		vector<int> ch;
		ch.push_back(i);
		perm(i, ch);
		ch.pop_back();
	}
	
//	for (auto it=s.begin();it!=s.end();it++){
//		cout << *it << endl;
//	}

	cout << s.size() << endl;
	
        
    return 0;
}
