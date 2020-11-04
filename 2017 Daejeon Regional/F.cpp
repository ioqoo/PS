#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m;
pair<ll,ll> go(ll a,ll b){
	if(a==2){
		if(b==1){
			return {1,1};
		}
		else if(b==2){
			return {1,2};
		}
		else if(b==3){
			return {2,2};
		}
		else{
			return {2,1};	
		}
	}
	ll num=a*a/4;
	if((b-1)/num==0){
		pair<ll,ll> cur=go(a/2,b);
		return {1+cur.second-1,1+cur.first-1};
	}
	else if((b-1)/num==1){
		pair<ll,ll> cur=go(a/2,b-num);
		return {1+cur.first-1,a/2+1+cur.second-1};
	}
	else if((b-1)/num==2){
		pair<ll,ll> cur=go(a/2,b-num*2);
		return {a/2+1+cur.first-1,a/2+1+cur.second-1};
	}
	else{
		pair<ll,ll> cur=go(a/2,b-num*3);
		return {a-cur.second+1,a/2-cur.first+1};
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	pair<ll,ll> answer=go(n,m);
	cout<<answer.first<<" "<<answer.second;
	
	return 0;
}


