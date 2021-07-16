#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1001;
const ll MOD = 1e9+7;

string grid[maxn];
ll dp[maxn][maxn];
ll solve(ll m, ll n)
{
	if(dp[m][n] != -1)
		return dp[m][n];
	if(grid[m][n] == '*')
        return dp[m][n] = 0;
	if(m == 0 && n == 0)
		return dp[m][n] = 1;
	ll ways = 0;
	if(m-1 >= 0 && grid[m-1][n] != '*')
		ways = (ways + solve(m-1, n)) % MOD;
	if(n-1 >= 0 && grid[m][n-1] != '*')
		ways = (ways + solve(m, n-1)) % MOD;
	return dp[m][n] = ways;
}

void iterative(ll n)
{
	memset(dp, 0, sizeof(dp));
	if(grid[0][0] != '*')
		dp[0][0] = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(grid[i][j] == '*')
			{
				dp[i][j] = 0;
				continue;
			}
			if(i-1 >= 0 && grid[i-1][j] !='*')
				dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
			if(j-1 >= 0 && grid[i][j-1] != '*')
				dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
		}
	}
	cout << dp[n-1][n-1];
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	memset(dp, -1, sizeof(dp));
	ll m;
	cin >> m;
	for(int i = 0; i < m; i++)
		cin >> grid[i];

	// RECURSIVE
	/*
    ll ans = solve(m-1, m-1);
    if(ans == -1)
    {
    	cout << 0;
    	return 0;
    }
    cout << ans;
    */

    // ITERATIVE
    iterative(m);
}
