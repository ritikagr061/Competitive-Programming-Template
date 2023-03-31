#include<bits/stdc++.h>
using namespace std;


void findFirstParent(int i, vector<bool> &vis, vector<int> adj[], vector<vector<int>> &parent)
{
	vis[i] = true;
	for (auto it : adj[i])
	{
		if (!vis[it])
		{
			parent[it][0] = i;
			findFirstParent(it, vis, adj, parent);
		}
	}
	return;
}



vector<vector<int>> BinaryLifting(int root, int n, vector<int> adj[])
{
	// create parent
	//return parent array where parent[x][i]=2^ith parent of x

	vector<vector<int>> parent(n + 1, vector<int>(log2(n) + 1, -1));
	vector<bool> vis(n + 1, false);
	findFirstParent(root, vis, adj, parent);

	for (int i = 1; i <= log2(n); i++)
	{
		for (int x = 1; x <= n; x++)
		{
			int intermediate = parent[x][i - 1];
			if (intermediate != -1)
				parent[x][i] = parent[intermediate][i - 1];
			else
				parent[x][i] = -1;
		}
	}

	return parent;
}

int kthParent(int x, int k, vector<vector<int>> &parent)
{
	// x=node of whose kth parent you want to find , k=yni , parent array = array returned by binary lifting function
	for (int i = 0; i <= log2(k); i++)
	{
		if ((1 << i)&k)
			x = parent[x][i];
	}
	return x;

	//T.C. = O(log k);
}

void dfsLevel(int i, vector<bool> &vis, int lvl, vector<int> adj[], vector<int> &level)
{
	// ith node , vis , lvl=level of ith node , adj , level vector
	vis[i] = true;
	level[i] = lvl;
	//cout << level[i] << endl;
	for (auto it : adj[i])
	{
		if (!vis[it])
		{
			dfsLevel(it, vis, lvl + 1, adj, level);
		}
	}
	return;
}

vector<int> levelOfNode(int root, int n, vector<int> adj[])
{
	// root of tree , n=size of node, adj=yni;
	vector<bool> vis(n + 1, false);
	vector<int> level(n + 1, 0);
	dfsLevel(root, vis, 0, adj, level);
	return level;
}

int findLCA(int a, int b, int n, vector<vector<int>> &parent, vector<int> &level)
{
	//a = first node , b=second node , n=total nodes
	//level vector required , and also parent vector returned from binary lifting
	if (level[a] > level[b])
		swap(a, b);

	///
	b = kthParent(b, level[b] - level[a], parent);

	if (a == b)
		return a;

	for (int i = log(n); i >= 0; i--)
	{
		int par1 = parent[a][i];
		int par2 = parent[b][i];

		if (par1 != -1 && par2 != -1 && par1 != par2)
		{
			a = par1;
			b = par2;
		}
	}

	return parent[a][0];
}


signed main() {
	// your code goes here

	//by default im taking root 1
	int root = 1;

	int n; cin >> n;
	vector<int> adj[n + 1];
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}


	vector<vector<int>> parent = BinaryLifting(root, n, adj);
	vector<int> level = levelOfNode(root, n, adj);

	//the node between which you wanna find LCA
	int a, b;
	cin >> a >> b;

	int lca = findLCA(a, b, n, parent, level);

	return 0;
}
