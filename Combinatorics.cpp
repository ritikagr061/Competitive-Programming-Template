#include<bits/stdc++.h>
using namespace std;
bool Bipartite(int i, vector<int> adj[], vector<int> &col)
{
    queue<int> q;
    q.push(i);
    col[i] = 1; //red

    while (!q.empty())
    {
        int popped = q.front();
        int color = col[popped];
        q.pop();
        for (auto it : adj[popped])
        {
            if (!col[it])
            {
                q.push(it);
                col[it] = (color == 1 ? 2 : 1);
            }
            else if (color == col[it])
                return false;
        }
    }

    return true;
}

bool isBipartite(int n, vector<int> adj[])
{
    vector<int> col(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (col[i] == 0) {
            if (!Bipartite(i, adj, col))
                return false;
        }
    }

    return true;
}
