#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3 * 1e5 + 5;
const int MOD = 1e9+7;
#define name(x) cout << (#x)
#define nline "\n"

// debug code
//vector
void debug(vector<ll> arr)
{
    cout  << endl;
    cout << "DEBUG : ";
    cout << " : [ ";
    for(auto u: arr)
        cout << u << " ";
    cout << "]" << endl;
}
//array
void debug(int arr[], int n)
{
    cout  << endl;
    cout << "DEBUG : ";
    cout << " : [ ";
    for(int i =0; i < n; i++)
        cout << arr[i] << " ";
    cout << "]" << endl;
}
//int
void debug(int a)
{
    cout << endl << "DEBUG : ";
    cout << " : "<< a << endl;
}
//vector<pair<d_type, d_type>>
void debug(vector<pair<int, int>> arr)
{
    cout  << endl;
    cout << "DEBUG : ";
    cout << " : [ ";
    for(auto pi: arr)
        cout << "(" << pi.first << ", " << pi.second << ")";
    cout << "]" << endl;
}

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
int white[maxn] = {0}, dp[maxn] = {0};
void dfs(int p, int c)
{
    dp[c] = white[c];
    for(auto v: adj[c])
    {
        if(p == v)
            continue;
        dfs(c, v);
        dp[c] += dp[v];
    }
}

void solve()
{
    int n;
    cin >> n;
    adj.resize(n+1);
    for(int i = 1; i <= n-1; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        if(x == 2)
        {
            white[v] = 1;
            white[u] = 1;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 1);
    vector<int> ans;
    for(int i = 1; i <= n; i++)
    {
        if(white[i] && dp[i] == 1)
            ans.push_back(i);
    }
    cout << ans.size() << nline;
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
