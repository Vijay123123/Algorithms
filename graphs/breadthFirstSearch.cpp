#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Read number of nodes and edges
    int n,m;
    cin>>n>>m;
    // Read edges
    vector <vector<int>> adj(n,vector<int> ());
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // BFS Start
    // visited array
    vector <int> vis(n,0);
    queue <int> q;
    // Start at 0 node
    q.push(0);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        if(!vis[node])
        {
            cout<<node<<" ";
            vis[node]=1;
            for(auto it:adj[node])
            {
                if(!vis[it])
                q.push(it);
            }
        }
    }
    return 0;
}