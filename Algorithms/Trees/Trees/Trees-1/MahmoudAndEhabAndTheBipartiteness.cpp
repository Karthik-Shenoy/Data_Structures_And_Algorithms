#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3 * 1e5 + 5;
const int MOD = 1e9+7;
#define name(x) cout << (#x)
#define nline "\n"

void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
// debug code
vector<vector<ll>> adj;
ll sz1 = 0, sz2 = 0;
ll dp[maxn] = {0};
void dfs(int p, int c, int st)
{
    if(st ==1)
    {
        dp[c] = 1;
        sz1++;
    }
    else
        sz2++;
    for(auto v: adj[c])
    {
        if(p == v)
            continue;
        dfs(c, v, 1-st);
    }
}

void solve()
{
    ll n;
    cin >> n;
    adj.resize(n+1);
    for(int i = 1; i <= n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 1, 1);
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(dp[i] == 1)
            ans += sz2 - (ll)(adj[i].size());
    }
    cout << ans << nline;
}

int main()
{
    init_code();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    //cin >> tc;
    while(tc)
    {
        solve();
        tc--;
    }
}
