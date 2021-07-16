#include<iostream>
using namespace std;
typedef long long ll;
const ll maxn = 10+1;

void solve()
{
	freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);

	ll n;
	cin >> n;
    ll grid[maxn][maxn];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char inp;
            cin >> inp;
            grid[i][j] = inp - '0';
        }
    }
	ll ans = 0;
	for(int i = n-1; i >= 0; i--)
	{
		for(int j = n-1; j >= 0; j--)
		{
			// if you dinf a tipped cow
			// flip the largest rectangle that can be formed at that step
			if(grid[i][j] == 1)
			{
				ans++;
				for(int k = 0; k <= i; k++)
				{
					for(int  l = 0; l <= j; l++)
					{
						grid[k][l] = 1 - grid[k][l];
					}
				}
			}

		}
	}
	cout << ans;
}

int main()
{
    solve();
}
