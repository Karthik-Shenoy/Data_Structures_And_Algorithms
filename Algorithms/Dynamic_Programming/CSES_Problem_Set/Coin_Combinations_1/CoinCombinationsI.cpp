// USE MOD(%) OPERATIONS WISELY IT MAY LEAD TO TLE AS IT IS VERY COSTLY TO PERFORM MODULO

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e6+1;
const ll MOD = 1e9+7;

ll dp[maxn]; vector<ll> coins;
ll solve(ll n)
{
	if(dp[n] != -1)
		return dp[n];
	if(n == 0)
		return dp[n] = 1;
	ll best = 0;
	for(auto x: coins)
	{
		if(n-x >= 0)
		{
			best = (best % MOD + solve(n - x) % MOD) % MOD;
		}
	}
	return dp[n] = best;
}

void iterative(ll n)
{
	dp[0] = 1;
	for(int i = 1;i <= n; i++)
	{
		dp[i] = 0;
		for(auto x: coins)
		{
			if(i-x >= 0)
				dp[i] = (dp[i] + dp[i-x]) % MOD;
		}
	}
    cout << dp[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	ll m, n;
	cin >> m >> n;
	coins.resize(m);
	for(auto &x: coins)
        cin >> x;

    // RECURSIVE SOLUTION
   	//cout << solve(n);

    // ITERATIVE SOLUTION
    iterative(n);

}
