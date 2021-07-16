#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define nline "\n"
const int maxn = 2*1e5+1;

vector<int> adj[maxn];
int selected[maxn] = {0};
int dp[maxn] = {0};
void dfs(int p, int c)
{
	int count = 0, maxi = -1, chosen_child, ans = 0;
	for(int v: adj[c])
	{
		if(v == p)
			continue;
        dfs(c, v);
		if(!selected[v])
		{
			if(dp[v] > maxi)
			{
				maxi = dp[v];
				chosen_child = v;
			}
		}
		ans += dp[v];
		count++;
	}
	if(count == 0)
	{
		dp[c] = 0;
		return;
	}
	if(maxi >= 0)
	{
		dp[c] = ans+1;
		selected[chosen_child] = 1;
		selected[c] = 1;
	}
	else
		dp[c] = ans;
	return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(-1, 1);
	cout << dp[1] << nline;
	return 0;
}
