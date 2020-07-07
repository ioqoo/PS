#include <bits/stdc++.h>

using namespace std;
typedef tuple<int, int, int> tp;
const int MAX = 1<<17;
const int INF = -1987654321;

int N, L;
tp arr[100005];

bool cmp(tp a, tp b){
    return get<1>(a) < get<1>(b);
}

int seg[2*MAX];
int num[2*MAX];
void update(int idx, int curr){
    seg[idx] = curr;
    if(curr==INF) num[idx] = 0;
    else num[idx] = 1;
    
    while(idx/2>=1){
        idx/=2;
        seg[idx] = max(seg[2*idx], seg[2*idx+1]);
        num[idx] = num[2*idx] + num[2*idx+1];
    }
}

int ans;
int solve(int x, int idx){
    int now = seg[idx];
    if(idx >= MAX){
        if(now<=x) return num[idx];
        else return 0;
    }
    
    if(now <= x) return num[idx];
    return solve(x,2*idx) + solve(x, 2*idx+1);
}
set<int> visited; 

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; ++i){
        int s, e;
        cin >> s >> e;
        if(e<s) swap(s,e);
        arr[i] = tp(i,s,e);
    }
    cin >> L;
    

    sort(arr, arr+N, cmp);
    fill(seg,seg+2*MAX,INF);
    
    queue<tp> candidate;
    int pre = 0;
    for(int i=0; i<N; ++i){
        int idx = get<0>(arr[i]);
        int s = get<1>(arr[i]);
        int e = get<2>(arr[i]);
        int LAST = s+L;
        if(visited.count(s)) continue;
        visited.insert(s);
        
        while(!candidate.empty()){ // 조건 빼기 
            int c_idx = get<0>(candidate.front());
            int c_s = get<1>(candidate.front());
            
            if(c_s >= s) break;
            
            update(MAX+c_idx, INF);
            candidate.pop();
        }
        
        while(pre<N){ // 조건 만족 넣기 
            int arr_idx = get<0>(arr[pre]);
            int arr_s = get<1>(arr[pre]);
            int arr_e = get<2>(arr[pre]);
            
            if(arr_s >= s && arr_s<=LAST){                
                update(MAX+arr_idx, arr_e);
                candidate.push(arr[pre]);
                
                pre++;
            }
            else break;
        }
        
        int temp = solve(LAST, 1);
        ans = max(ans, temp);
    }

    cout << ans << '\n';
    

    return 0;
}



