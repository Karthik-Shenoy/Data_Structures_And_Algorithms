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
vector<vector<int>> adj;
int diameter = INT_MIN;
int F[maxn]={0}, G[maxn] = {0};
void dfs(int p, int c)
{
    vector<int> fvals;
    for(auto v:adj[c])
    {
        if(v == p) continue;
        dfs(c, v);
        fvals.push_back(F[v]);
    }
    sort(fvals.begin(), fvals.end());
    if(fvals.size() >= 1)
        F[c] = fvals.back() + 1;
    if(fvals.size() >= 2)
        G[c] = fvals.back() + fvals[fvals.size() - 2] + 2;
    diameter = max(diameter, max(F[c], G[c]));
}

void solve()
{
    int n;
    cin >> n;
    adj.resize(n+1);
    for(int i = 1; i <= n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n == 1)
    {
        cout << 0 << nline;
        return;
    }
    dfs(0, 1);
    cout << 3 * (diameter) << nline;
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
