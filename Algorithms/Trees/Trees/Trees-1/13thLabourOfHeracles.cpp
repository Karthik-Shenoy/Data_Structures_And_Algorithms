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
vector<vector<ll>> adj;
void solve()
{
    ll n;
    cin >> n;
    adj.clear();
    adj.resize(n+1);
    ll sum = 0;
    vector<ll> vals(n+10, 0), deg(n+10, 0);
    for(int i = 1; i <= n; i++)
    {
        cin >> vals[i];
        sum += vals[i];
    }
    vector<ll> edges(n+1, 0);
    for(int i = 1; i <= n-1; i++)
    {
        ll u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++; 
    }
    vector<ll> to_sort;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < deg[i]; j++)
            to_sort.push_back(vals[i]);
    }
    sort(to_sort.begin(), to_sort.end());
    for(auto itr = to_sort.rbegin(); itr != to_sort.rend(); itr++)
    {
        ll v = *itr;
        cout << sum << " ";
        sum+=v;
    }
    cout << sum << nline;
}

int main()
{
    init_code();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    cin >> tc;
    while(tc)
    {
        solve();
        tc--;
    }
}
