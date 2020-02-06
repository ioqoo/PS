#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
 
vector<int> graphList[100];
int n,m;
int main()
{
    //input
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++){
        int s,e;
        scanf("%d%d",&s,&e);
        graphList[s].push_back(e);
        graphList[e].push_back(s);
    }
    //output
    for(int i=1; i<=n; i++){
        printf("%d : ",i);
        for(int j=0; j<graphList[i].size(); j++){
            printf("%d ",graphList[i][j]);            //vector 배열은 이렇게 2차원 배열처럼[]연산자를 사용해서 표현가능
        }
        printf("\n");
    }
 
    return 0;
}