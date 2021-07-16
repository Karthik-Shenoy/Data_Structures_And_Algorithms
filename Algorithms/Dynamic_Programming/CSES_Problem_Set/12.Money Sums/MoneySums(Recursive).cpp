#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 1e5+1;
#define nline "\n"

int arr[maxn];

//int **dp = new int* [101];
vector<vector<int>> dp(101, vector<int>(maxn, -1));


int solve(int n, int s)
{
	if(dp[n][s] != -1)
		return dp[n][s];
	if(n == 0 && s == 0)
		return dp[n][s] = 1;
    if(n == 0 && s != 0)
        return dp[n][s] = 0;
	int ans = solve(n-1, s);
	if(s - arr[n-1] >= 0)
		ans = ans | solve(n-1, s - arr[n-1]);
	return dp[n][s] = ans;
}

int main()
{
    /*
    for(int i = 0;i < 101; i++)
        dp[i] = new int[maxn];
    */
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, sum = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	for(int i = 0 ; i <= n; i++)
    {
        for(int j = 0; j <= sum; j++)
            dp[i][j] = -1;
    }
	for(int i = 1 ; i <= sum; i++)
    {
        solve(n, i);
    }
    /*
	for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= sum; j++)
            cout << dp[i][j] << " ";
        cout << nline;
    }
    */
    vector<int> ans;
    for(int i = 1; i <= sum; i++)
    {
        if(dp[n][i])
            ans.push_back(i);
    }
    cout << ans.size() << nline;
    for(auto x: ans)
        cout << x << " ";
}
