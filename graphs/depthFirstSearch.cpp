#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector <vector<int>> &adj,vector <int> &vis)
{
    vis[node]=1;
    cout<<node<<" ";
    for(auto it:adj[node])
    {
        if(!vis[it])
        dfs(it,adj,vis);
    }
}
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
    // visited array
    vector <int> vis(n,0);
    // DFS Start
    dfs(0,adj,vis);
    return 0;
}
