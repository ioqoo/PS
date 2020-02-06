#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000001;

int _lower_bound(int start, int end, int *arr, int target) {
    int mid;
    while (end - start > 0) {
        // �־��� ����[start,end]���� Ž���ϵ��� �Ѵ�. start == end�̸� �ݺ� ����
        mid = (start + end) / 2;
        // �־��� ������ �߰� ��ġ�� ����Ѵ�
        if (arr[mid] < target) start = mid + 1;
        // ã���� �ϴ� ������ ������ ���������� �� ĭ�� �� ���� ���� ����
        else end = mid;
        // ã���� �ϴ� ������ ũ�� �ű���� �� ���� ����
    }
    return end + 1; // ã�� ������ ���� ��� ���� ������ +1 ��ġ ����
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    int i, n, j = 0;
    int cnt = 0;
    int lis[MAX]; // 1001 : ���ڿ� �ִ� ���̰� 1000
    int arr[MAX];
    scanf("%d", &n);
    for (i = 0; i<n; ++i) scanf("%d", &arr[i]);

    i = 0;
    lis[i] = arr[i];
    i++;

    while (i < n) {
        // lis�� ���� ū ������ �� ū���� ������
        if (lis[j] < arr[i]) {
            lis[j + 1] = arr[i];
            j++;
        }
        else {
            int ans = _lower_bound(0, j, lis, arr[i]);
            lis[ans - 1] = arr[i];
        }
        i++;
    }
    printf("%d", j + 1);
    return 0;
}
