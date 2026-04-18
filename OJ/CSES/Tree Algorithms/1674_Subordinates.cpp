#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define endl '\n'
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define input(v) for(auto &it:v)cin>>it
#define inputa(a,n,ind) for(i=0;i<n;i++)cin>>a[i+ind]
#define output(v) for(auto &it:v)cout<<it<<" "
#define outputa(a,n,ind) for(i=0;i<n;i++)cout<<a[i+ind]<<" "
#define outputl(v) for(auto &it:v)cout<<it<<'\n'
#define outputal(a,n,ind) for(i=0;i<n;i++)cout<<a[i+ind]<<'\n'

#define maxn (int)(2e5+100)
#define M 998244353

template <class T>
struct comparator
{
    bool operator()(const T &a, const T &b) const
    {
        return a < b;
    }
};

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
using ordered_setd = tree<T, null_type, greater<T>, rb_tree_tag,
                          tree_order_statistics_node_update>;
int dfs(int u,int *visited,int *ans,vector<vector<int>>&graph)
{
    if(visited[u])return 0;
    visited[u]=1;

    int count=0;
    for(auto v:graph[u])
    {
        if(!visited[v])count+=dfs(v,visited,ans,graph);
    }

    ans[u]=count;
    return count+1;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int>>graph(n+1);
    int i;
    for(i=2;i<=n;i++)
    {
        int u;
        cin>>u;
        graph[u].push_back(i);
    }

    int ans[n+1]={};
    int visited[n+1]={};

    for (i = 1; i <= n; i++)
    {
        dfs(i,visited,ans,graph);
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}