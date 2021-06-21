#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e6+2;
const ll MOD = 1e9+7;


ll dp[maxn];
ll solve(ll n)
{
	if(dp[n] != -1)
		return dp[n];
	if(n == 0)
		return dp[n] = 1;
	ll count = 0;
	for(int i = 1; i <= 6; i++)
	{
		if(n-i >= 0)
			count = (count % MOD + solve(n-i) % MOD) % MOD;
	}
	return dp[n] = count;
}

void iterative(ll n)
{
    memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		dp[i] = 0;
		for(int k = 1; k <= 6; k++)
		{
			if(i-k >= 0)
				dp[i] = (dp[i] % MOD + dp[i-k] % MOD) % MOD;
		}
	}
	cout << dp[n] % MOD;
}

int main()
{
	ll n;
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	//memset(dp, -1, sizeof(dp));
	cin >> n;
	//cout << solve(n);
	iterative(n);
}
