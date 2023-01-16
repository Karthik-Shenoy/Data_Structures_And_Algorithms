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
ll dp[maxn]={0}, ans[maxn]= {0}, vals[maxn] = {0};
void dfs(ll p, ll c)
{
    dp[c] = vals[c] == 1 ? 1: -1;
    for(auto v:adj[c])
    {
        if(p == v) continue;
        dfs(c,v);
        dp[c] += max(0LL, dp[v]);
    }
}

void dfs1(ll p, ll c, ll partial)
{
    ans[c] = max(0LL, partial) + dp[c];
    for(auto v: adj[c])
    {
        if(p == v) continue; 
        dfs1(c, v, ans[c] - max(0LL, dp[v]));
    }
}
void solve()
{
    ll n;
    cin >> n;
    adj.clear();
    adj.resize(n+1);
    for(int i = 1; i <= n; i++)
        cin >> vals[i];
    for(int i = 1; i <= n-1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 1);
    dfs1(0, 1, 0);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << nline;
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
