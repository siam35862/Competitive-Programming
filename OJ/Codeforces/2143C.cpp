#include<bits/stdc++.h>
using namespace std;

#define int long long 

void dfs(int u,int *visited,vector<int>&toposort,vector<vector<int>>&graph)
{
    if(visited[u])return;
    visited[u]=1;
    for(auto v:graph[u])dfs(v,visited,toposort,graph);
    toposort.push_back(u);
}
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>>graph(n+1);
        int i;
        for(i=0;i<n-1;i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            if(x<y)graph[u].push_back(v);
            else graph[v].push_back(u);
        }

        vector<int>toposort;
        int visited[n+1]={};
        for(i=1;i<=n;i++)
        {
            dfs(i,visited,toposort,graph);
        }
            reverse(toposort.begin(),toposort.end());
        int ans[n+1];
        int ind=0;
        for(auto it:toposort)
        {
            ans[it]=++ind;
            
        }
      
        for(i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
}