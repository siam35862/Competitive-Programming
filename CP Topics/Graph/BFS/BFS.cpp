#include<bits/stdc++.h>
using namespace std;

#define int  long long
#define inf INT64_MAX
void bfs(int src,vector<vector<int>>&graph,int *level,vector<int>&traversal)
{
    level[src]=0;
    queue<int> q;
    q.push(src);
    int visited[graph.size()]={};

    while(q.size()>0)
    {
        auto it=q.front();
        q.pop();
        if(!visited[it])
        {
            traversal.push_back(it);
            visited[it]=1;

            for(auto u:graph[it])
            {
                if(!visited[u])
                {
                    q.push(u);
                    level[u]=min(level[it]+1,level[u]);
             
                }
            }
        }
    }
}
int32_t main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>>graph(n+1);
    int i;
    int u,v;
    
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int src;
    cin>>src;

    int level[n+1];
    for(i=1;i<=n;i++)level[i]=inf;
    vector<int>traversal;

    bfs(src,graph,level,traversal);

    cout<<"Shortest distance from "<<src<<endl;
    for(i=1;i<=n;i++)cout<<i<<" : "<<level[i]<<endl;

    cout<<"Graph traversal from source "<<src<<" using BFS\n";
    for(auto it:traversal)cout<<it<<" ";
    cout<<endl;

}
