#include<bits/stdc++.h>
using namespace std;
#define ll long long
// check 

ll dep[1000000];

void dfs(ll node,ll parent,ll depth,vector <vector <ll>> &adj,vector <vector <ll>> &par) {
    
    dep[node]=depth;
    par[node][0]=parent;
    
    for(auto child:adj[node]) {
        
        if(child!=parent) {
            
            dfs(child,node,depth+1,adj,par);
        }
    }
}

void process(ll n,vector <vector <ll>> &edges) {
    // 0-based indexing , undirected tree
    
    ll maxdepth=log2(n)+1;
    vector <vector <ll>> adj(n),par(n,vector <ll> (maxdepth,-1));
    
    for(auto e:edges) {
        
        ll u=e[0],v=e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    memset(dep,0,n);
    
    dfs(0,-1,0,adj,par);
    
    // finding 2th pow parent of every node 
    
    for(ll i=1;i<maxdepth;i++) {
        
        for(ll node=0;node<n;node++) {
            
            if(par[node][i-1]!=-1) {
                
                par[node][i]=par[par[node][i-1]][i-1];
            }
        }
    }
    
    
    
}

int main() {
    ll n,m; cin>>n>>m;
    vector <vector <ll>> edges;
    
    for(ll i=0;i<m;i++) {
        ll u,v; cin>>u>>v;
        edges.push_back({u,v});
    }
    
    // process function requires no of nodes, edge list of u,v 
    process(n,edges);
}