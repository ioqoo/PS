#include <iostream>

using namespace std;

struct Trie{
	bool is_marked = false;
	Trie* child[26];
	
	Trie(){
		for (int i=0;i<26;i++){
			child[i] = nullptr;
		}
	}
	~Trie(){
		for (int i=0;i<26;i++){
			if (child[i] != nullptr){
				delete child[i];
			}
		}
	}
	
	void insert(char *s){
		if (*s == '\0') { // 재귀적으로 구현. 끝까지 온 상태 
			is_marked = true;
			return; 
		}
		if (child[*s - 'a'] == nullptr){ // 이번 간선을 타고 만들어진 노드가 없으면 
			child[*s - 'a'] = new Trie(); // 새 노드 생성 
		}
		child[*s - 'a'] -> insert(s + 1); // s는 포인터 : s+1은 다음 글자를 가르킬 것임 
	}
}*root;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	// 트라이 : 문자열 사전. 여러 개의 문자열을 저장하고 자유롭게 꺼내 활용할 수 있게 하는 자료구조
	
	// ex) print, the, poem, pri
	// 처음엔 루트 노드 하나 가짐. 루트 노드부터 시작해서 단어를 한 글자씩 잘라서 저장.
	// 간선을 여러개 둘 건데, a ~ z 간선까지.
	// print 부터 -> p 간선을 타고 노드 하나 만들고, r 간선 타고... t 간선 타고 노드 생성.
	// the -> t 간선, h 간선, e 간선
	// poem -> p 간선은 print에서 이미 함 -> o 간선, e 간선, m 간선
	// pri -> p 간선, r 간선은 이미 있고, i 간선. 
	// 문제마다 다르지만, 보통 단어가 끝날 때 마킹을 해줌. 
	
	root = new Trie();
	char print[] = "print"; // string 안 됨 
	root->insert(print);
	
	
	return 0;
}
