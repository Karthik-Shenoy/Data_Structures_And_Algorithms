#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define nline "\n"

vector<vector<int>> adj;
vector<int> dp;
void dfs(int p, int c)
{
	int count = 0;
	for(int v:adj[c])
	{
		if(v == p)
			continue;
		dfs(c, v);
		count += dp[v]+1;
	}
	dp[c] = count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
	cin >> n;
    adj.resize(n+1);
    dp.resize(n+1);
	for(int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	dfs(-1, 1);
	for(int i = 1; i <=n ;i++)
		cout << dp[i] << " ";
	cout << nline;
}
