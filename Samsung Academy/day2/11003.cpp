#include <bits/stdc++.h>
#define MAX 5000005
#define INF 2000000000
#define ll long long

using namespace std;

int N, L;
int nums[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &N, &L);

    multiset<int> s;
    int s_size = 0;

    for (int i=0;i<N;i++){
        int temp;
        scanf("%d", &temp);
        nums[i] = temp;
        if (s_size < L){
            s.insert(temp);
            s_size++;
            printf("%d ", *(s.begin()));
        }
        else{
            s.erase(s.find(nums[i-L]));
            s.insert(temp);
            printf("%d ", *(s.begin()));
        }
//        printf("\n");
//        for (multiset<int>::iterator iter=s.begin(); iter!=s.end();iter++){
//            printf("%d ",*iter);
//        }
//        printf("\n");

    }




    return 0;
}
