#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

int main(){
	// getline(cin, string) : 공백 포함 한 줄을 문자열(문자 배열)에 저장
	// \n을 앞이랑 뒤에서 다 읽음
	// vector<int> vt(k, x) : k개의 x로 vector를 채워넣고 시작
	
	// * map으로 파이썬 dict처럼 하기
	// -> if(m.count(input)) m[input]++; else m[input] = 1;

	// * 위상정렬
	// indegree가 0인 정점을 큐에 넣는다
	// 정점 개수만큼 반복
	//	: 큐의 front 원소를 빼고 그 정점에서 나가는
	//	  간선을 모두 삭제, 이때 삭제 후 indgree가 0이 된
	//	  새로운 정점이 생기면 그것도 큐에 넣는다
	// 	  큐에서 빼는 정점 순서가 위상 정렬 결과
	//	  중간에 큐가 비면 불가능(사이클 존재)
	//	  결과는 여러개가 있을 수 있는데, 정점 번호가 작은 것부터 나열하라고 하면
	//	  큐 대신 최소 힙을 이용하면 가능

	// 펜윅트리 장점 : 배열의 연속된 부분을 동일하게 조절할 수 있다
	// update(2, 1); update(4, -1)를 하면
	// 2부터 3까지의 구간합이 1 늘어난 것이지만 이것을 배열로 생각해보면
	// ftree의 2번째 index는 1~2의 구간합이므로 1,
	// 3번째 index는 3번째 원소 자체이므로 0이다
	// 여기서 sum(2)은 1이고, sum(3) 역시 1이다
	// 결과적으로 sum들의 배열로 생각해보면, a부터 b-1까지만 1이 더해진 것과 같다

	// 정점 문자를 0~51 사이의 번호로 바꿔주는 간단한 함수
	// 	int CtoI(char c){
	// 	    if(c <= 'Z') return c - 'A';
	// 	    return c - 'a' + 26;
}

	// 큰 수에 대한 mod 연산
int mod(char *S, int p) {
	// S는 수를 문자열로 표현한 것, 1324 -> "1324"
	int ret = 0;
	for (int i=0;S[i];i++) ret = (ret*10 + (S[i]-'0')) % p;
	return ret;
}