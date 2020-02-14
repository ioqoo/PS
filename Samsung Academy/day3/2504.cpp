#include <bits/stdc++.h>
#define MAX 10005
#define ll long long

using namespace std;

stack<int> st;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    while(scanf("%c", &curr) != EOF){
        printf("%c ", curr);
        if (curr == '('){
            st.push(-1);
        }
        else if (curr == '['){
            st.push(-2);
        }
        else if (curr == ')'){
            if (st.empty()) {
                printf("0");
                return 0;
            }
            else if (st.top() != -1){
                printf("0");
                return 0;
            }
            else{
                st.pop();
                st.push(2);
            }

        }
    }


    return 0;
}
