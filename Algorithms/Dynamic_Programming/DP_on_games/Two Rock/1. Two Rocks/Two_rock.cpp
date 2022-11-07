#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const ll maxn = 101;


int main()
{
	ll m,n, dp[maxn][maxn];
	//Inputs for number of rocks in each pile [left, right]
	cin >> m >> n;
	memset(dp, 0, sizeof(dp));

	//if there is only one rock remaining in either of the piles the player who moves currently wins
	dp[1][0] = 1;
	dp[0][1] = 1;
	//if ther is one rock each in both the piles player who moves currently wins
	dp[1][1] = 1;
	/*dp[i][j] --> can the player who's moving currently win if there are i rocks in the left pile
	  and j rocks in the second pile*/
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			bool possibility = false;
			/*if the player who moves currently will lead to the winning state of the other player
			  the current player lose other wise he wins*/
			if(i - 1 >= 0)
				possibility = possibility | (1-dp[i-1][j]);
			if(j-1 >= 0)
				possibility = possibility | (1-dp[i][j-1]);
			if(i-1 >= 0 && j-1 >= 0)
				possibility = possibility | (1-dp[i-1][j-1]);
			/*as both players play optimally we always choose the choice which leads to the current
			  player winning the game, if there is any such choice */
			dp[i][j] = dp[i][j] | possibility;
		}
	}
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
}
