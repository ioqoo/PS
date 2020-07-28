#include <bits/stdc++.h>

const int MAX = 26;
using namespace std;

bool visited[4][4];
char grid[4][4];
unordered_set<string> find_list;
int score[] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct Trie{
    Trie* child[MAX];
    bool is_ended = false;
    
    Trie(){
        memset(child, NULL, sizeof(child));
        is_ended = false;
    }
    ~Trie(){
        for (int i=0;i<MAX;i++){
            if (child[i]!=nullptr) {
                delete child[i];
            }
        }
    }
    
    void insert(string word){
        Trie* curr_node = this;
        for (int i=0;i<word.size();i++){
            int letter = word[i] - 'A';
            if (curr_node->child[letter] == nullptr){
                curr_node->child[letter] = new Trie();
            }
            curr_node = curr_node->child[letter];
        }
        curr_node->is_ended = true;
    }
    
    bool search(Trie* node, string word){
        Trie* curr_node = node;
        
        for (int i=0;i<word.size();i++){
            int letter = word[i] - 'A';
            if (curr_node->child[letter] == nullptr){
                return false;
            }
            curr_node = curr_node->child[letter];
        }
        
        return (curr_node != nullptr && curr_node->is_ended);
    }
    
    void dfs(int i, int j, string word){
        if (word.size() > 8) return;
        
        visited[i][j] = true;
        char curr_letter = grid[i][j];
        word += curr_letter;
        Trie* node = child[curr_letter-'A'];
        if (node == nullptr){
            visited[i][j] = false;
            return;
        }
        if (node->is_ended){
            find_list.insert(word);
        }
        
        for (int d=0;d<8;d++){
            int ni = i + di[d], nj = j + dj[d];
            if (ni<0 || ni>=4 || nj<0 || nj>=4) continue;
            if (visited[ni][nj]) continue;
            node->dfs(ni, nj, word);
        }
        visited[i][j] = false;
    }
};



int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    string word;
    Trie* root = new Trie();
    for (int i=0;i<N;i++){
        cin >> word;
        root->insert(word);
    }
    
    int b;
    cin >> b;
    for (int t=0;t<b;t++){
        for (int i=0;i<4;i++){
//            cin >> grid[i];
            for (int j=0;j<4;j++){
                cin >> grid[i][j];
            }
        }
        find_list.clear();
        
        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                root->dfs(i, j, "");
            }
        }
        
        int total_score = 0;
        string longest_word = "";
        for (auto it=find_list.begin();it!=find_list.end();it++){
            string curr_word = *it;
            if (longest_word.size() < curr_word.size()){
                longest_word = curr_word;
            }
            else if (longest_word.size() == curr_word.size()){
                longest_word = min(longest_word, curr_word);
            }
            total_score += score[curr_word.size()];
        }
        
        cout << total_score << " " << longest_word << " " << find_list.size() << "\n";
    }
    
    

    return 0;
}



