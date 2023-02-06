bool rec(int node, int& n, int& m, bool adj[][101], vector<int> clr)
    {
        if(node == n+1)
            return true;
        bool ans = 0;
        for(int c = 1; c <= m; c++)
        {
            bool possible = true;
            for(int v = 0; v < n; v++)
            {
                if(v != node && adj[node][v] && clr[v] == c)
                {
                    possible = false;
                    break;
                }
            }
            if(possible)
            {
                clr[node] = c;
                if(rec(node+1, n, m, adj, clr))
                    return true;
                clr[node] = -1;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> clr(101, -1);
        bool ans = 0;
        ans = rec(0, n, m, graph, clr);
        return ans;
    }