#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool rec(int i, int su, vector<vector<int>>& dp, int arr[])
{
    if(dp[i][su] != -1)
        return dp[i][su];
    if(i == 0)
        return dp[i][su] = (su == 0);
    if(su == 0)
        return dp[i][su] = 1;
    bool ans = rec(i-1, su, dp, arr);
    if(su-arr[i-1] >= 0)
        ans |= rec(i-1, su-arr[i-1], dp, arr);
    return dp[i][su] = ans;
}
int equalPartition(int N, int arr[])
{
    // code here
    int su = 0;
    for(int i = 0; i < N; i++)
        su += arr[i];
    vector<vector<int>> dp(101, vector<int>(100001, -1));
    if(su%2 != 0)
        return 0;
    return rec(N, su/2, dp, arr);
}

int main()
{
    int n;
    cin >> n;
    int arr[101];
    for(int i = 0; i < n; i++)  cin >> arr[i];
    cout << equalPartition(n, arr);
}