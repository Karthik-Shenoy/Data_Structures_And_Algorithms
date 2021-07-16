#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1e2+1;
#define nline "\n"


int main()
{
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
	int n, arr[maxn], sum = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	vector<vector<int>> dp(sum+1, vector<int>(n+1, 0));
	dp[0][0] = 1;

	for(int i = 0; i <= n; i++)
		dp[0][i] = 1;

	for(int i = 0; i <= sum; i++)
	{
		for(int j = 1; j <= n; j++)
		{
            dp[i][j] = dp[i][j-1];
			if(i - arr[j-1] >= 0)
				dp[i][j] = dp[i][j] | dp[ i - arr[j-1] ][j-1];
		}
	}


	vector<int> ans;
	for(int i = 1; i <= sum; i++)
	{
		if(dp[i][n] == 1)
			ans.push_back(i);
	}
	cout << ans.size() << nline;
	for(auto x: ans)
		cout << x << " ";
}
