#include<iostream>
#include<vector>
using namespace std;
#define nline "\n"
const int maxn = 501;
const int MOD = 1e9 + 7;

int main()
{
    int n;
	cin >> n;
	int sum = (n*(n+1))/2;
	vector<vector<int>> dp(sum/2+1, vector<int>(n+1, 0));
	if(sum % 2 != 0 )
	{
		cout << 0;
		return 0;
	}
	dp[0][0] = 1;

	for(int i = 1; i <=sum/2 ;i++)
		dp[i][0] = 0;

	for(int i = 0; i <= sum/2; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			dp[i][j] = dp[i][j-1] % MOD;
			if(i - j >= 0)
				dp[i][j] = (dp[i][j] + dp[i-j][j-1]) % MOD;
		}
	}
	cout << (long long)((long long)dp[sum/2][n] * 500000004) % MOD;
}
