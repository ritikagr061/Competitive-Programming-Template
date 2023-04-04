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
