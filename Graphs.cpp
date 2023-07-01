#include<bits/stdc++.h>
 
using namespace std;

bool isBipartite(int n,vector<int> adj[])
{
  vector<int> col(n+1,0);
  queue<int> q;
	q.push(1);
	col[1] = 1; //red
	//red=1,blue=0
  
	while (!q.empty())
	{
		int x = q.front();
		int color = col[x];
		q.pop();
		for (auto it : adj[x])
		{
			if (!col[it])
				q.push(it),col[it] = (color == 1 ? 2 : 1);
			else
				if (color == col[it]) return false;
		}
	}
 
	return true;
}


bool isCyclic_nonDirect_helper(int currNode, int n, vector<int> adj[], vector<bool> &vis, int parent) {
    vis[currNode] = true;
    for (auto it : adj[currNode]) {
        if (vis[it] && it != parent)
            return true;
        else if (!vis[it]) {
            if (isCyclic_nonDirect_helper(it, n, adj, vis, currNode))
                return true;
        }
    }
    return false;
}

bool isCyclic_nonDirect(int n, vector<int> adj[]) {
    //used when nodes number must start from 1 and go till +inf
    vector<bool> vis(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (isCyclic_nonDirect_helper(i, n, adj, vis, -1))
                return true;
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isCyclic_nonDirect(n, adj))
        cout << "cycle";

    return 0;
}



