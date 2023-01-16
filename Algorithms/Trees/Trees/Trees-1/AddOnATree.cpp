#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5001;
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

void solve()
{
    int n;
    cin >> n;
    vector<int> degree(n+1, 0);
    for(int i = 0; i <  n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(degree[i] == 2)
        {
            cout << "NO" << nline;
            return;
        }
    }
    cout << "YES" << nline;
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
