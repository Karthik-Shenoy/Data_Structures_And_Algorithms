#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> ret;

void rec(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<bool>> vis, string path)
{
    if(i == n-1 && j == n-1)
    {
        ret.push_back(path);
        return;
    }
    int dir[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    char dir_char[] = {'D', 'U', 'R', 'L'};
    vis[i][j] = 1;
    for(int k = 0; k < 4; k++)
    {
        int ni = i + dir[k][0], nj = j + dir[k][1];
        if(ni < n && nj < n && ni >= 0 && nj >= 0 && !vis[ni][nj] && matrix[ni][nj])
            rec(ni, nj, n, matrix, vis, path + dir_char[k]);
    }
    return;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    // Your code goes here
    vector<vector<bool>> vis(n, vector<bool>(n, 0));
    if(m[0][0])
        rec(0,0,n,m,vis,"");
    return ret;
}