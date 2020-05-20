#include<iostream>
#include<vector>
#include<math.h>
#include<cstring>
#include<queue>
#include <cstdio>
#include<utility>
#include <algorithm>
#include<string>
#include<set>
#include<list>
#include<functional>
using namespace std;

int N;
vector<int> weight;
vector<int>res;
int cache[2001];
int LDS[2001];
int LIS[2001];
const int INF = 98765431;

int binary_search(int lo, int ro, int target)
{
	int ans = INF;
	int mid;
	while (lo < ro)
	{
		mid = (lo + ro) / 2;

		if (res[mid] > target)
			lo = mid + 1;
		else if (res[mid] < target)
			ro = mid;
	}
	return mid;
}
int lds(int start)//자기자신을 제외한 
{
	res.clear();
	res.push_back(INF);

	for (int i = start; i < N; i++)
	{
		int key = weight[i];
		
		//!
		if (weight[start] < key)
			continue;

		if (res.back() >= key)
			res.push_back(key);
		else
		{
			int index=binary_search(0, res.size() - 1, key);
			res[index] = key;
		}
	}
	return res.size() - 1;
}
int lis(int start)
{
	res.clear();
	vector<int>res;
	res.push_back(-INF);
	for (int i = start; i < N; i++)
	{
		int key = weight[i];

		//!
		if (weight[start] > key)
			continue;

		if (res.back() < key)
			res.push_back(key);
		else
		{
			vector<int>::iterator iter = lower_bound(res.begin(), res.end(), weight[i]);
			*iter = weight[i];
		}
	}
	return res.size() - 1;
}
int main()
{
    freopen("input.txt", "r", stdin);
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		weight.push_back(tmp);
	}
	for (int i = 0; i < N; i++)
	{
		LDS[i] = lds(i);
		LIS[i] = lis(i);
	}
	for (int i = 0; i < N; i++)
		ans = max(ans, LDS[i] + LIS[i] - 1);

	cout << ans;
}
