#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>

#define MAX 30

using namespace std;

int N;
vector<string> words;
vector<int> graph[MAX];
int indegree[MAX];
bool appear[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    string temp;
    for (int i=0;i<N;i++){
        cin >> temp;
        words.push_back(temp);
        for (char c: temp){
            appear[c-'a'] = true;
        }
    }
    
    string previ, curr;
    for (int i=0;i<N-1;i++){
        previ = words[i];
        curr = words[i+1];
        int prev_size = previ.size();
        int curr_size = curr.size();
        int range = min(prev_size, curr_size);
        for (int i=0;i<range;i++){
            if (previ[i] != curr[i]){
                graph[previ[i]-'a'].push_back(curr[i]-'a');
                indegree[curr[i]-'a']++;
                break;
            }
            if (i==range-1 && prev_size > curr_size){
                cout << "!\n";
                return 0;
            }
        }
    }
    int cnt = 0;
    for (int i=0;i<26;i++){
        if (appear[i]) cnt++;
    }
    
    
    queue<int> Q;
    for (int i=0;i<26;i++){
        if (appear[i] && indegree[i] == 0) {
            Q.push(i);
        }
    }
    
    bool multi = false;
    vector<char> ans;
    for (int i=0;i<cnt;i++){
        if (Q.empty()){
            cout << "!\n";
            return 0;
        }
        if (Q.size() >= 2){
            multi = true; // 바로 탈출하면 X 
        }
        int curr = Q.front();
        Q.pop();
        ans.push_back(curr + 'a');
        for (int next: graph[curr]){
            indegree[next]--;
            if (indegree[next] == 0){
                Q.push(next);
            }
        }
    }
    if (multi){
        cout << "?\n";
        return 0;
    }
    for (char c: ans){
        cout << c;
    }
    
    return 0;
}
