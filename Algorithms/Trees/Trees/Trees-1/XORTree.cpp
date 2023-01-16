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

vector<vector<ll>> adj;
vector<int> init;
vector<int> goal;
vector<int> ans;
void dfs(int p, int c, int ocnt, int ecnt, int level, int& cnt)
{
    if(level % 2 == 0)
    {
        int curr = (init[c] + ecnt) % 2;
        int change = 0;
        if(curr != goal[c])
        {
            change = 1;
            cnt++;
            ans.push_back(c);
        }
        for(auto v:adj[c])
        {
            if(p == v) continue;
            dfs(c,v,ocnt, ecnt+change, level+1, cnt);
        }
    }
    else
    {
        int curr = (init[c] + ocnt) % 2;
        int change = 0;
        if(curr != goal[c])
        {
            cnt++;
            change = 1;
            ans.push_back(c);
        }
        for(auto v:adj[c])
        {
            if(p == v) continue;
            dfs(c,v,ocnt+change, ecnt, level+1, cnt);
        }
    }
}

// debug code
void solve()
{
    int n;
    cin >> n;
    adj.resize(n+1);
    init.resize(n+1);
    goal.resize(n+1);
    for(int i=1; i <= n-1; i++)
    {
        int  u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i =1; i <= n; i++)
        cin >> init[i];
    for(int i = 1; i <= n; i++)
        cin >> goal[i];
    int count = 0;
    dfs(-1, 1, 0, 0, 1, count);
    cout << count << nline;
    for(auto x:ans)
        cout << x << nline;

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
