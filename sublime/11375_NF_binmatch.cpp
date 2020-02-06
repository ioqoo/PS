#include <bits/stdc++.h>
#define ll long long
#define MAX 1001

using namespace std;

// Bipartite Matching
// O(VE) , V : 양쪽 그룹 원소 개수 중 큰 것
// 왜? 에드먼드 카프로 돌릴 거 -> min(O(VE^2), O((V+E)f))인데,
// f가 O(V)이므로 (이분매칭도 결국 NF! source에서 sink로 최대 f만큼 갈 수 있다)
// 이분매칭을 생각해보면 최악의 경우에도 유량을 흘려주는 짓을 V번만 한다

int n, m, A[MAX], B[MAX];
vector<int> graph[MAX]; // graph[i] : A의 i번째 원소에서 갈 수 있는 B의 원소들
bool visited[MAX];

bool dfs(int a){
	printf("------\n");
	visited[a] = true;
	for (int b: graph[a]){
		// ** if문 해석
		// || 기준으로
		// 왼쪽 : a의 반대편이 매칭이 안되어 있음
		// 오른쪽
		//   !visited[B[b]] : 이번 사이클에서 매칭이 됐는지 안 됐는지
		//   && dfs(B[b]) : 매칭은 됐는데 한번 더 돌려보기

		//   A의 1은 B의 1과 2랑,
		//   A의 2도 B의 1과 2랑 연결되어있다고 해보자(연결 != 매칭, '연결'은 매칭 될 수 있는 후보라는 뜻)
		//   맨 처음 A1과 B1이 매칭
		//   main 함수에서 다음 dfs(2)를 돌리는데
		//   A2랑 연결되어있는 B1은 이미 연결되어있는 상태
		//   -> 그럼 B[b]==0에서 안 된다
		//   그럼 ||를 넘어서 오른쪽 부분을 봐야 하는데,
		//   !visited[B[b]]에서 B[1]은 1로 저장되어있고,
		//   visited[1]은 현재는 false -> !visited[1] = true가 되므로 short circuit에 안 걸리고 && 너머로 통과
		//   그럼 이제 다시 dfs(B[b]) = dfs(1)을 돌린다
		//          => 이 부분부터 A1이 B1말고 매칭 시킬 다른 B원소 있나 보는 부분
		//   여기서 visited[1] = true가 되고,
		//   A1와 연결된 B의 원소들을 쭉 볼건데, 가장 먼저 나오는 건 B1
		//   B[1] = 1이므로 || 너머로 넘어가고,
		//   visited[1]이 true이므로 바로 다음으로 넘어간다!!
		//   그 말은 이 시점부터는 || 기준으로 오른쪽은 무조건 안되고, 왼쪽이 되야 매칭을 시켜준다는 뜻
		//   다시 말해서 B1말고, A1에서 갈 수 있는 다른 B의 후보들을 찾을 건데,
		//   그 B의 후보가 아직 A중에서 아무하고도 매칭이 안 되어 있어야 한다는 뜻
		if (B[b] == 0 || !visited[B[b]] && dfs(B[b])){
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d %d", &n, &m);
	for (int i=1;i<=n;i++){
		int S;
		scanf("%d", &S);
		for (int j=0;j<S;j++){
			int v;
			scanf("%d", &v);
			graph[i].push_back(v);
		}
	}

	int match = 0;
	for (int i=1;i<=n;i++){
		if (A[i] == 0){
			fill(visited, visited+n, false);
			if(dfs(i)) match++;
		}
	}
	printf("%d\n", match);
}