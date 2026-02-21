#include<bits/stdc++.h>
using namespace std;
#define int long long 
struct edge{
    int u,v,cost;
};


vector<edge>edges;
void finding_negative_cycle(int n)
{
    int distance[n+1]={};
    vector<int>p(n+1,-1);
    int x;
    for(int i=0;i<n;i++)
    {
        x=-1;
        for(edge e:edges)
        {
            if(distance[e.u]+e.cost<distance[e.v])
            {
                distance[e.v]=distance[e.u]+e.cost;
                p[e.v]=e.u;
                x=e.v;
            }
        }
    }
    if(x==-1)cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        for(int i=0;i<n;i++)x=p[x];
        int st=x;
        vector<int>ans;
        while(p[x]!=st)
        {
            ans.push_back(x);
            x=p[x];
        }
        cout<<st<<" "<<x<<" ";
        reverse(ans.begin(),ans.end());
        for(auto it: ans)cout<<it<<" ";
        cout<<endl;

       
    }
}
int32_t main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        edges.push_back({u,v,cost});
    }
    finding_negative_cycle(n);

}