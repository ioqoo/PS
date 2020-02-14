#include <iostream>
#include <cstdio>
#include <vector>

#define MAX 10005

using namespace std;

int V, E;
vector<int> graph[MAX];
int order[MAX]; // order �� �湮 ���α��� �ѹ��� üũ (0�̸� �̹湮)
bool ans[MAX];
int cnt;

int dfs(int x, bool isRoot){
	// isRoot�� �� ��尡 root ������� -> root ����� �� �ڽ��� ������ 2�� �̻��̶�� ������
	
	order[x] = ++cnt; // �湮������ cnt�� �÷����� order �迭�� �Է����ְ�,
	int ret = order[x]; // �̹� ����� �湮 ������ ret�� ����
	
	int child = 0;
	for (int next: graph[x]){
		if (!order[next]){ // ������ ��� �� �湮�� ����, 
			child++;
			int low = dfs(next, false); // ��������� ���� ����� low ���� �޾ƿͼ� 
			if (!isRoot && order[x] <= low){
			// root ��尡 �ƴϰ�, �������� �Ǵ� ������ "order <= ���� ����� low" �� �����ϸ� 
				ans[x] = true; // ������ üũ 
			}
			ret = min(ret, low); 
			// Line 25����ó�� ��������� low ���� �������־�� �ϱ� ������ 
			// ������ ���� �߿��� min(curr ����� order, ������ ������ order(else ��), ������ ������ low)��
			// �̹� ����� low�� ���� 
		}
		else{
			ret = min(ret, order[next]);
		}
	}
	
	if (isRoot){
		ans[x] = (child >= 2);
	}
	return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	scanf("%d %d", &V, &E);
	for (int i=0;i<E;i++){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for (int i=1;i<=V;i++){
		if (!order[i]) dfs(i, true);
	}
	
	int cnt = 0;
	for (int i=1;i<=V;i++){
		if (ans[i]) cnt++;
	}
	printf("%d\n", cnt);
	for (int i=1;i<=V;i++){
		if (ans[i]) printf("%d ", i);
	}
}
