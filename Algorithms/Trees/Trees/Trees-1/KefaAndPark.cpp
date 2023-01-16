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

vector<vector<int>> adj;
void dfs(ll p, ll c, vector<ll>& nodes, vector<ll>& in_sub, ll x)
{
    if(c == x)
        in_sub[c] = 1;
    nodes[c] = 1;
    for(auto v:adj[c])
    {
        if(v == p) continue;
        dfs(c,v,nodes,in_sub,x);
        in_sub[c] |= in_sub[v];
        nodes[c] += nodes[v];
    }
}

// debug code
void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    adj.resize(n+1);
    for(int i = 1; i <= n-1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> nodes(n+1, 0), in_sub(n+1, 0);
    dfs(-1, y, nodes, in_sub, x);
    ll nc=0, nc2 = nodes[x];
    for(auto v:adj[y])
    {
        if(in_sub[v])
        {
            nc = n - nodes[v];
            break;
        }
    }
    cout << (n*(n-1)) - (nc * nc2) << nline;
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
