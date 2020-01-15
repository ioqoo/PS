#include <bits/stdc++.h>
#define MAX 1005

using namespace std;

int grid[MAX][MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str1, str2;
    cin >> str1 >> str2;

    int str1_size = str1.length();
    int str2_size = str2.length();

    for (int i=1;i<=str1_size;i++){
        for (int j=1;j<=str2_size;j++){
            if (str1[i-1] == str2[j-1]) {
                grid[i][j] = grid[i-1][j-1] + 1;
            }
            else {
                grid[i][j] = max(grid[i-1][j], grid[i][j-1]);
            }
        }
    }
//    for (int i=1;i<=str1_size;i++){
//        for (int j=1;j<=str2_size;j++){
//            printf("%d ", grid[i][j]);
//        }
//        printf("\n");
//    }

    cout << grid[str1_size][str2_size] << "\n";

    stack<char> ans;

    int i = str1_size, j = str2_size;

    while(grid[i][j] != 0){
        // �� ������ ������ ���� ���� �ö���鼭
        // ���ʰ� ���� ��ΰ� ���纸�� ���� ������ ã���� �ö���� �񱳸�
        // �ؿ�ó�� �ߴµ�

        /*
        if (grid[i][j] > grid[i][j-1] && grid[i][j] > grid[i-1][j]){
            ans.push_back(str2[j-1]);
            i--;
            j--;
            curr--;
        }
        else{
            if (grid[i][j] > grid[i][j-1] && grid[i][j] == grid[i-1][j]){
                i--;
            }
            else if (grid[i][j] > grid[i-1][j] && grid[i][j] == grid[i][j-1]){
                j--;
            }


        }
        */

        // �ð� �ʰ��� ����. �� ������ ���̰� ���� ����???


        if (grid[i][j] == grid[i-1][j]){
            i--;
        }
        else if (grid[i][j] == grid[i][j-1]){
            j--;
        }
        else{
            ans.push(str2[j-1]);
            i--;
            j--;
        }
    }

    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }

}
