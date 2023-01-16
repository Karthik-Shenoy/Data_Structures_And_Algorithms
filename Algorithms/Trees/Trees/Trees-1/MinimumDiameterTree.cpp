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
double diameter = LLONG_MIN;
double f[maxn] = {0}, g[maxn] = {0};
void dfs(ll p, ll c, vector<double>& vals)
{
    if(c == 1)
        f[c] = vals[c];
    vector<pair<double, int>> f_vals;
    for(auto v: adj[c])
    {
        if(p == v) continue;
        dfs(c, v, vals);
        f_vals.push_back({f[v], v});
    }
    sort(f_vals.begin(), f_vals.end());
    if(f_vals.size() >= 1)
    {
        pair<double, int> pi = f_vals.back();
        f[c] += pi.first + vals[pi.second];
    }
    if(f_vals.size() >= 2)
    {
        pair<double, int> pi1 = f_vals.back();
        pair<double, int> pi2 = f_vals[f_vals.size() - 2];
        g[c] = pi1.first + pi2.first;
        g[c] += vals[pi1.second] + vals[pi2.second];
    }
    diameter = max(diameter, max(f[c], g[c]));
}

void solve()
{
    ll n;
    double s;
    cin >> n >> s;
    adj.clear();
    adj.resize(n+1);
    vector<double> vals(n+1, 0);
    vector<int> deg(n+1, 0);
    for(int i = 1; i <= n-1; i++)
    {
        ll u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    double cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] == 1)
            cnt++;
    }
    for(int i = 1;i <= n; i++)
    {
        if(deg[i] == 1)
            vals[i] = s/cnt;
    }
    dfs(0, 1, vals);
    cout << setprecision(16) << diameter << nline;;
    return;
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
