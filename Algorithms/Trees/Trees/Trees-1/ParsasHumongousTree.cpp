#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2 * 1e5 + 5;
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
ll dp[maxn][2];
void dfs(ll p, ll c, vector<pair<int, int>>& vals)
{
    dp[c][1] = dp[c][0] = 0;
    ll l = vals[c].first, r = vals[c].second;
    for(auto v:adj[c])
    {
        if(p == v) continue;
        dfs(c,v, vals);
        dp[c][0] += max(abs(l - vals[v].first)+dp[v][0], abs(l - vals[v].second)+dp[v][1]);
        dp[c][1] += max(abs(r - vals[v].first)+dp[v][0], abs(r - vals[v].second)+dp[v][1]);
    }
}

void solve()
{
    ll n;
    cin >> n;
    adj.clear();
    adj.resize(n+1);
    vector<pair<int, int>> vals(n+1); 
    for(int i = 1; i <= n; i++)
        cin >> vals[i].first >> vals[i].second;
    for(int i = 1; i <= n-1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 1, vals);
    cout << max(dp[1][0], dp[1][1]) << nline;
    return;
}

int main()
{
    init_code();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    cin >> tc;
    while(tc)
    {
        solve();
        tc--;
    }
}
