#include<bits/stdc++.h>
using namespace std;
#define nline "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p;
	cin >> n >> p;
	vector<int> pages(n), value(n);
	vector<vector<int>> dp(n+1,vector<int>(p+1,0));

	for(int &x: value)
		cin >> x;
	for(int &x: pages)
		cin >> x;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= p; j++)
		{
			dp[i][j] = dp[i-1][j];
			if(j - value[i-1] >= 0)
            {
                //cout << i-1 << " " << j - value[i-1] <<endl;
				dp[i][j] = max(dp[i][j], dp[i-1][ j-value[i-1] ] + pages[i-1]);
            }
		}
	}
	cout << dp[n][p];
	return 0;
}
