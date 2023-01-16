#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5001;
const int MOD = 1e9+7;
#define name(x) cout << (#x)
#define nline "\n"

// debug code
vector<vector<int>> adj;

void dfs(int p, int c, vector<int>& ans)
{
    ans[c] = p;
    for(auto v:adj[c])
    {
        if(v == p) continue;
        dfs(c, v, ans);
    }
}

void solve()
{
    int n, r1, r2;
    cin >> n >> r1 >> r2;
    adj.resize(n+1);
    for(int i = 1; i <= n; i++)
    {
        if(i == r1) continue;
        int v;
        cin >> v;
        adj[i].push_back(v);
        adj[v].push_back(i);
    }
    vector<int> ans(n+1, 0);
    dfs(0, r2, ans);
    for(int i = 1; i <= n; i++)
    {
        if(i == r2) continue;
        cout << ans[i] << " ";
    }
    cout << nline;
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
