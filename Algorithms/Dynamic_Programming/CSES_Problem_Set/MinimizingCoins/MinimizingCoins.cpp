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
		return dp[n] = 0;
	ll best = INT_MAX;
	for(auto x: coins)
	{
		if(n-x >= 0)
		{
			best = min(best, solve(n - x)+1);
		}
	}
	return dp[n] = best;
}

void iterative(ll n)
{
	memset(dp, 0, sizeof(dp));
	dp[0] = 0;
	for(int i = 1;i <= n; i++)
	{
		dp[i] = INT_MAX;
		for(auto x: coins)
		{
			if(i-x >= 0)
				dp[i] = min(dp[i], dp[i-x]+1);
		}
	}
	if(dp[n] == INT_MAX)
		cout << -1;
	else
		cout << dp[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	memset(dp, -1, sizeof(dp));
	ll m, n;
	cin >> m >> n;
	coins.resize(m);
	for(auto &x: coins)
        cin >> x;

    // RECURSIVE SOLUTION
    /*
	ll ans = solve(n);
	if(ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
    */

    // ITERATIVE SOLUTION
    iterative(n);

}
