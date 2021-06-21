#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e6+1;
const ll MOD = 1e9+7;


ll dp[maxn];
ll createArray(ll arr[], ll n)
{
	ll index = 0;
	while(n)
	{
	    if(n%10 == 0)
        {
            n/=10;
            continue;
        }
		arr[index++] = n%10;
		n = n/10;
	}
	return index;
}

ll solve(ll n)
{
    //cout << n;
	if(dp[n] != -1)
		return dp[n];
	if(n == 0)
		return dp[n] = 0;
	ll nums[10];
	ll m = createArray(nums, n);
	ll best = INT_MAX;
	for(int i = 0; i < m; i++)
	{
		if(n-nums[i] >= 0)
			best = min(best, solve(n-nums[i])+1);
	}
	return dp[n] = best;
}

void iterative(ll n)
{
	dp[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		ll nums[10];
		ll m = createArray(nums, i);
		dp[i] = INT_MAX;
		for(int j = 0;j < m;j++)
		{
			if(i - nums[j] >= 0)
				dp[i] = min(dp[i], dp[i-nums[j]]+1);
		}
	}
	cout << dp[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	memset(dp, -1, sizeof(dp));
	ll n;
	cin >> n;

	//RECURSIVE
	//cout << solve(n);

	//Iterative
	iterative(n);
}
