#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e6+2;
const ll MOD = 1e9+7;

//ll dp[maxn][101] --> dp matrix for recursive solution
//ll **dp;
ll dp[maxn]; // iterative dp array

ll m;
vector<ll> coins;

//recursive solution which does not work
/*
ll solve(ll n, ll last_choice)
{
    cout << n << " " << last_choice << endl;
	if(dp[n][last_choice] != -1)
		return dp[n][last_choice];
	if(n == 0)
		return dp[n][last_choice] = 1;
	ll ways = 0;
	for(int i = last_choice; i < m; i++)
	{
		if(n - coins[i] >= 0)
			ways = (ways + solve(n-coins[i], i)) % MOD;
	}
	return dp[n][last_choice] = ways;
}
*/

void iterative(ll n)
{
	dp[0] = 1;
	for(int k = 0; k < m; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			if(i-coins[k] >= 0)
				dp[i] = (dp[i] + dp[i-coins[k]])%MOD;
		}
	}
	cout << dp[n];
}


int main()
{
    // DP MATRIX FOR RECURSION
    /*
    dp = new ll* [maxn];
    for(int i = 0; i < maxn; i++)
		dp[i] = new ll [101];
	*/
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	ll n;
	cin >> m >> n;

	memset(dp, 0, sizeof(dp));

	//initialization-----------------
	//recursion
	/*
    for(int i = 0; i <= n+1; i++)
    {
        for(int j = 0; j <= m+1; j++)
            dp[i][j] = -1;
    }
    */
    //-------------------------------

	coins.resize(m);
	for(auto &x: coins)
		cin >> x;
    sort(coins.begin(), coins.end());
    iterative(n);
    //recursive Solution which does not work
	//cout << solve(n, 0);
}
