#include <bits/stdc++.h>
#define ll long long

const int MAX = 5105;
const ll MOD = 1e9+7;

using namespace std;

int N, M, S, T, sccnum, cnt, startsn, endsn;
int order[MAX], sn[MAX], sccindeg[MAX], sccval[MAX], sccmax[MAX];
int scc_size[MAX];
vector<int> graph[MAX], sccgraph[MAX];
bool finished[MAX], cango[MAX];
stack<int> st;
queue<int> Q;

bool temp_scc_graph[MAX][MAX];

int dfs(int curr){
    order[curr] = ++cnt;
    st.push(curr);
    int ret = order[curr];
    for (int next: graph[curr]){
        if (order[next] == 0) ret = min(ret, dfs(next));
        else if (!finished[next]) ret = min(ret, order[next]);
    }
    if (ret == order[curr]){
        while(1){
            int t = st.top();
            st.pop();
            sn[t] = sccnum;
            sccmax[sn[t]]++;
            sccval[sn[t]]++;
            finished[t] = true;
            if (t == curr) break;
        }
        sccnum++;
    }
    return ret;
}

ll fact(ll n){
	ll ret = 1;
	for(ll i=n;i>1;i--){
		ret = (ret*i)%MOD;
	}
	return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    int N;
    scanf("%d", &N);
    
    for (int i=0;i<N;i++){
    	for (int j=0;j<N;j++){
    		int temp;
    		scanf("%d", &temp);
    		if (temp == 1){
    			graph[i].push_back(j);
			}
		}
	}
    
    for (int i=0;i<N;i++){
        if (order[i] == 0) dfs(i);
    }
    
    startsn = sn[S], endsn = sn[T];
    
    for (int curr=0;curr<N;curr++){
        int currsn = sn[curr];
        for (int next: graph[curr]){
            int nextsn = sn[next];
            if (currsn != nextsn){
            	temp_scc_graph[currsn][nextsn] = true;
//                sccgraph[currsn].push_back(nextsn);
//                sccindeg[nextsn]++;
            }
        }
    }

	for (int i=0;i<sccnum;i++){
		for (int j=0;j<sccnum;j++){
			if (i==j) continue;
			if (temp_scc_graph[i][j]) {
				sccgraph[i].push_back(j);
				sccindeg[j]++;
			}
		}
	}
	

//	for (int i=0;i<sccnum;i++){
//		for (auto n: sccgraph[i]){
//			printf("%d ", n);
//		}
//		printf("\n");
//
//	}
    
    for (int i=0;i<N;i++){
    	scc_size[sn[i]]++;
	}
    bool inQ[MAX] = {0,};
    for (int i=0;i<sccnum;i++){
        if (sccindeg[i] == 0) {
        	Q.push(i);
        	inQ[i] = true;
		}
    }
    
    ll ans = 1;
    int sccorder[MAX] = {0,};
    int C = 0;
    
    while(!Q.empty()){
        int curr = Q.front();
//        printf("%d\n", curr);
        sccorder[curr] = C++;
        Q.pop();
        inQ[curr] = false;
//        printf("%d\n", curr);
        for (int next: sccgraph[curr]){
//        	printf("%d ", next);
        	sccindeg[next]--;
            if (sccindeg[next] == 0) {
//            	ans = (ans * (ll)scc_size[next]) % MOD;
            	if (!inQ[next]) Q.push(next);
			}
//			printf("curr ans : %lld\n", ans);
        }
//        printf("\n");
    }
    
//    for (int i=0;i<sccnum;i++){
//    	printf("%d ", sccorder[i]);
//	}
//	printf("\n");
	
	for (int curr=0;curr<sccnum;curr++){
		int curr_order = sccorder[curr];
		int min_order = 1000;
		int min_order_num = -1;
//		printf("curr : %d\n", curr);
		for (int next: sccgraph[curr]){
//			printf("%d\n", next);
			int next_order = sccorder[next];
			if (curr_order < next_order){
				if (next_order < min_order){
					min_order = next_order;
					min_order_num = next;
				}
			}
		}
//		printf("curr : %d / curr_order : %d / min_order : %d / min_order_num : %d\n", curr, curr_order, min_order, min_order_num);
		if (min_order_num == -1) continue;
		ans = (ans * (ll)scc_size[min_order_num])%MOD;
	}
    
    for (int i=0;i<sccnum;i++){
    	ans = (ans * fact((ll)(scc_size[i]-1)) )%MOD;
	}
    
	printf("%d\n", ans);
    

    return 0;
}



