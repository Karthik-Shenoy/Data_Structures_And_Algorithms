#include<iostream>
#include<string.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e3+1;

void solve()
{
	freopen("breedflip.in", "r", stdin);
	freopen("breedflip.out", "w", stdout);
	ll n; string s1, s2;
	cin >> n;
	cin >> s1 >> s2;
	bool found = false;
	ll ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(s1[i] != s2[i])
		{
			if(!found)
			{
				found = true;
				ans++;
			}
		}
		else
			found = false;
	}
	cout << ans;
	return;
}

int main()
{
	solve();
}
