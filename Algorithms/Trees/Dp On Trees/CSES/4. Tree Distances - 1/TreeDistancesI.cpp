#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define nline '\n'
typedef long long ll;

vector<vector<int>> adj;
void dfs(int p, int c, vector<int>& dist)
{
	for(auto v: adj[c])
	{
		if(v == p) continue;
		dist[v] = dist[c]+1;
		dfs(c, v, dist);
	}
}


void solve()
{
	int n;
	cin >> n;
	vector<int> dist_x(n+1, 0), dist_y(n+1, 0), dist_r(n+1, 0);
	adj.resize(n+1);
	for(int i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, 1, dist_r);
	int x = 1, y=1;
	for(int i = 1; i <= n; i++)
	{
		if(dist_r[x] < dist_r[i])
			x = i;
	}
	dfs(0, x, dist_x);
	for(int i = 1; i <= n; i++)
	{
		if(dist_x[y] < dist_x[i])
			y = i;
	}
	dfs(0, y, dist_y);
	for(int i = 1; i <= n; i++)
	{
		cout << max(dist_x[i], dist_y[i]) << " ";
	}
	cout << nline;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc = 1;
	//cin >> tc;
	while(tc)
	{
		solve();
		tc--;
	}
}