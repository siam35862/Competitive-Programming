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
#define maxsize 100000005
#define max_n 262144 + 100

#define M 1000000007

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
    tree<T, null_type, comparator<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_setd = tree<T, null_type, greater<T>, rb_tree_tag,
                          tree_order_statistics_node_update>;
int bin_exp(int a, int b)
{
    if (b == 0)
        return 1;
    int v = bin_exp(a, b / 2);
    if (b % 2 == 0)
        return (v * v) % M;
    else
        return (((v * v) % M) * a) % M;
}

void dfs(int u,int *count,vector<vector<int>>&graph)
{
    count[u]=1;
    for(auto v:graph[u])
    {
        dfs(v,count,graph);
        count[u]+=count[v];
    }
}
void dfs(int u,int *count,int *ans,int p,vector<vector<int>>&graph)
{
    if(p==-1)ans[u]=count[u]*2-1;
    else ans[u]=(ans[p]+count[u]*2-1)%M;
    for(auto v:graph[u])
    {
        dfs(v,count,ans,u,graph);
    
    }
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int n,i;
        cin >> n;

        vector<vector<int>>graph(n+1);
        int count[n+1]={};
        for(i=1;i<=n;i++)
        {
            int l,r;
            cin>>l>>r;

            if(l!=0)graph[i].push_back(l);
            if(r!=0)graph[i].push_back(r);

        }

        int ans[n+1]={};
        dfs(1,count,graph);
       // cout<<count[1]<<endl;
        dfs(1,count,ans,-1,graph);

        //remaining part ?
       

       
    }
    return 0;
}