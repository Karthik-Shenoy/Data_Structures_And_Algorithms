#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+1;
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
vector<int> ans;
int dfs(int p, int c)
{
    int count = 0, l_nodes = 0;
    for(auto v: adj[c])
    {
        if(v == p) continue;
        l_nodes += dfs(c, v);
        count++;
    }
    if(count == 0)
        return 1;
    else
    {
        ans.push_back((l_nodes >= 3));
        return 0;
    }
}

void solve()
{
    int n;
    cin >> n;
    adj.resize(n+1);
    for(int u = 2; u <= n; u++)
    {
        int v;
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ok = true;
    dfs(0, 1);
    for(auto p:ans)
        ok &= p;
    string ans = ok ? "Yes" : "No";
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