#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool possible(int& i, int& j, vector<int>& pos)
{
    int n = pos.size();
    int dir[][2] = {{1,0}, {1,1}, {1,-1}, {-1,0}, {-1,1}, {-1,-1}, {0,1}, {0,-1}};
    for(int k = 0; k < 8; k++)
    {
        int p = i + dir[k][0], q = j + dir[k][1];
        while(p < n && q < n && p >= 0 && q >= 0)
        {
            if(pos[q] == p+1)
                return false;
            p += dir[k][0]; q += dir[k][1];
        }
    }
    return true;
}

void rec(int col, int n, vector<vector<int>>& ans, vector<int> temp)
{
    if(col == n)
    {
        ans.push_back(temp);
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(possible(i, col, temp) == 1)
        {
            temp[col] = i+1;
            rec(col+1, n, ans, temp);
            temp[col] = -1;
        }
    }
    return;
}

vector<vector<int>> nQueen(int n) {
    // code here
    vector<vector<int>> ans;
    vector<int> temp(n,-1);
    rec(0,n,ans,temp);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> ret;
    ret = nQueen(n);
    for(auto arr: ret)
    {
        for(auto x: arr)
            cout << x << ' ';
        cout << "\n";
    }
}