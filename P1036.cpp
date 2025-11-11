#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
using namespace std;
int n, m;
int a[21];
int ans = 0;
map<int, int> mp;//映射找次数 排除同一数字的不同解
int ar[10000000];//存储值
int ss(int h)
{
	if (h == 1) return 0;
	else if (h == 2) return 1;
	else if (h == 0) return 0;
	else if ((h & 1) == 0) return 0;
	for (int i = 3;i * i <= h;i += 2)
	{
		if (h % i == 0) return 0;
	}
	return 1;
}
int hx = 0;
void dg(int bu, int temp, int ind)
{
	if (bu == m)
	{
		mp[temp]++;
		if (mp[temp] == 1)//如果没有出现过
		{
			ar[hx++] = temp;//存入值
		}
	}
	else
	{
		for (int i = ind;i < n;i++)//递归
		{
			dg(bu + 1, temp + a[i], i + 1);
		}
	}
}
int main()
{
	int maxs = -1;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	dg(0, 0, 0);
	for (int i = 0;i < hx;i++)
	{
		if (ss(ar[i]))
		{
			ans += mp[ar[i]];
		}
	}
	cout << ans;
}