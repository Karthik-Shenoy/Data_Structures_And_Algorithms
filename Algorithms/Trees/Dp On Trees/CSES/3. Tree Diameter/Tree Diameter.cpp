#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2*1e5 + 5;
#define nline "\n"

int dp[maxn] = {0};
int best = -1;
vector<int> adj[maxn];

pair<int,int> best_choice(vector<int> arr)
{
	int maxi =-1, s_maxi = -1, maxi_dex, n = arr.size();
	for(int i = 0; i < n; i++)
	{
		if(arr[i] > maxi)
		{
			maxi = arr[i];
			maxi_dex = i;
		}
	}
	for(int i = 0; i < n;i++)
	{
		if(arr[i] > s_maxi and i!=maxi_dex)
			s_maxi = arr[i];
	}
	return {maxi, s_maxi};
}

void dfs(int p, int c)
{
	vector<int> distances;
	for(int v:adj[c])
	{
		if(p == v)
			continue;
		dfs(c, v);
		distances.push_back(dp[v]);
	}
	dp[c] = distances.size() == 1 ? distances[0]+1 : dp[c];
	best = max(best, dp[c]);
	if(distances.size() > 1)
	{
		pair<int, int>pi = best_choice(distances);
		dp[c] = *max_element(distances.begin(), distances.end()) + 1;
		best = max(best, max(dp[c], pi.first+pi.second+2));
	}
	return;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(-1, 1);
	cout << best << nline;
	return 0;
}
