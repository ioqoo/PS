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
		if (*s == '\0') { // ��������� ����. ������ �� ���� 
			is_marked = true;
			return; 
		}
		if (child[*s - 'a'] == nullptr){ // �̹� ������ Ÿ�� ������� ��尡 ������ 
			child[*s - 'a'] = new Trie(); // �� ��� ���� 
		}
		child[*s - 'a'] -> insert(s + 1); // s�� ������ : s+1�� ���� ���ڸ� ����ų ���� 
	}
}*root;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	// Ʈ���� : ���ڿ� ����. ���� ���� ���ڿ��� �����ϰ� �����Ӱ� ���� Ȱ���� �� �ְ� �ϴ� �ڷᱸ��
	
	// ex) print, the, poem, pri
	// ó���� ��Ʈ ��� �ϳ� ����. ��Ʈ ������ �����ؼ� �ܾ �� ���ھ� �߶� ����.
	// ������ ������ �� �ǵ�, a ~ z ��������.
	// print ���� -> p ������ Ÿ�� ��� �ϳ� �����, r ���� Ÿ��... t ���� Ÿ�� ��� ����.
	// the -> t ����, h ����, e ����
	// poem -> p ������ print���� �̹� �� -> o ����, e ����, m ����
	// pri -> p ����, r ������ �̹� �ְ�, i ����. 
	// �������� �ٸ�����, ���� �ܾ ���� �� ��ŷ�� ����. 
	
	root = new Trie();
	char print[] = "print"; // string �� �� 
	root->insert(print);
	
	
	return 0;
}
