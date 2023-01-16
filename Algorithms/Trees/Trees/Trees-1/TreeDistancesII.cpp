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
ll subsum[maxn]={0}, subnodes[maxn]= {0}, ans[maxn] = {0};
void dfs(ll p, ll c)
{
    ll sum = 0;
    ll nodes = 1;
    for(auto v:adj[c])
    {
        if(p == v) continue;
        dfs(c,v);
        sum += subsum[v]+subnodes[v];
        nodes += subnodes[v];
    }
    subsum[c] = sum;
    subnodes[c] = nodes;
}

void dfs1(ll p, ll c, ll partial, ll& total_nodes)
{
    ans[c] = subsum[c] + partial + (total_nodes - subnodes[c]);
    for(auto v: adj[c])
    {
        if(p == v) continue;
        dfs1(c, v, ans[c] - subsum[v] - subnodes[v], total_nodes);
    }
}
void solve()
{
    ll n;
    cin >> n;
    adj.clear();
    adj.resize(n+1);
    for(int i = 1; i <= n-1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 1);
    dfs1(0, 1, 0, n);
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
