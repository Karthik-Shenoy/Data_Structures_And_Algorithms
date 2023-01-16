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
int respect[maxn];
void dfs(int p, int c, vector<int>& ans)
{
    bool flag = respect[c];
    for(auto v: adj[c])
    {
        if(p == v)continue;
        dfs(c, v, ans);
        flag &= respect[v];
    }
    if(flag)
        ans.push_back(c);
}

void solve()
{
    int n;
    cin >> n;
    adj.resize(n+1);
    int root = 1;
    for(int i = 1; i <= n; i++)
    {
        int v, k;
        cin >> v >> k;
        respect[i] = k;
        if(v == -1)
        {
            root = i;
            continue;
        }
        adj[i].push_back(v);
        adj[v].push_back(i);  
    }
    vector<int> ans;
    dfs(0, root, ans);
    sort(ans.begin(), ans.end());
    if(ans.size() == 0)
    {
        cout << -1 << nline;
        return;
    }
    for(auto x: ans)
        cout << x << " ";
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
