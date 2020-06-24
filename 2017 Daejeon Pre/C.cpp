#include <bits/stdc++.h>

using namespace std;

int W;
string P;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> W;
    cin >> P;
    
    set<char> arr;
    arr.insert('(');
    arr.insert(')');
    arr.insert('[');
    arr.insert(']');
    arr.insert('S');
    arr.insert('S');
    arr.insert('L');
    arr.insert('B');
    arr.insert(',');
    arr.insert(' ');
    
    bool ok = true;
    int E_f = 0;
    int E_b = 0;
    int V = 0;
    
    stack<char> St;
    bool comma = false;
    for(int i=0; i<P.length(); ++i){
        
        
        char now = P[i];
        if(!arr.count(now)) ok = false;
        if(now==','){
            if(comma) comma = false;
            else ok = false;
        }
        else{
            if(now == ' ') continue;
            if(now == 'S'){
                if(comma) ok = false;
                comma = true;
                
                V++;
                E_f++;
            }
            else if(now=='L'){
                if(comma) ok = false;
                comma = true;
                
                V++;
                E_f+=2;
                E_b++;
            }
            else if(now=='B'){
                if(comma) ok = false;
                comma = true;
                
                V++;
                E_f+=2;
            }
            else if(now=='(' || now=='['){
                if(!comma) ok = false;
                comma = false;
                
                St.push(now);
            }
            else if(now == ')'){
                
                
                
                V++;
                if(St.top()=='(') St.pop();
                else ok = false;
            }
            else if(now==']'){
                
                
                
                V++;
                if(St.top() == '[') St.pop();
                else ok = false;
            }
            
        }
        
    }
    if(!St.empty()) ok = false;

    if(!ok) cout << -1 << '\n';
    else{
        cout << E_f << " , " << E_b << " , " << V << '\n';
        cout << E_f + W*E_b - V + 2 << '\n';
    }
    return 0;
}



