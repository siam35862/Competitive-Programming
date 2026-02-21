#include<bits/stdc++.h>
using namespace std;

#define int long long

void dfs(int u,int val,int *visited,vector<vector<int>>&graph,vector<vector<int>>&ans,map<pair<int,int>,int>&mp)
{
    if(visited[u])return;
    visited[u]=1;
    int st=1;

    for(auto v:graph[u])
    {
        if(!visited[v])
        {
            if(st==val)st++;
            ans[st].push_back(mp[{u,v}]);
           // cout<<st<<" : "<<mp[{u,v}]<<endl;
            dfs(v,st,visited,graph,ans,mp);
            st++;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    map<pair<int,int>,int>mp;
    int i;
    vector<vector<int>>graph(n+1);
    for(i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        mp[{u,v}]=mp[{v,u}]=i;
        graph[u].push_back(v);
        graph[v].push_back(u);

    }
    vector<vector<int>>ans(n+1);
    int visited[n+1]={};
    dfs(1,0,visited,graph,ans,mp);

    int mx=0;
    for(i=1;i<=n;i++)
    {
        if(ans[i].size()>0)mx=i;
        else break;
    }
    cout<<mx<<endl;
    for(i=1;i<=mx;i++)
    {
        cout<<ans[i].size()<<" ";
        for(auto it:ans[i])cout<<it<<" ";
        cout<<endl;
    }
}