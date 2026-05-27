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

pair<int,int> dp[405][405];

pair<int,int> minimumDp(int *a,int i,int j,int &ans)
{
    if(i>j)return {0,0};
    if(i==j)return {a[i],0};
    
    if(dp[i][j].first)return dp[i][j];

    int mn=INT64_MAX;
    pair<int,int> p={INT64_MAX,INT64_MAX};

    for(int k=i;k<j;k++)
    {
        auto p1=minimumDp(a,i,k,ans);
        auto p2=minimumDp(a,k+1,j,ans);
        if(p1.first+p2.first+p1.second+p2.second<p.second)
        {
            mn=p1.first+p2.first;
            p={mn,p1.second+p2.second+mn};
        }
        // cout<<i<<" "<<k<<" "<<j<<" "<<val<<endl;
    }
    
    return dp[i][j]=p;
    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,i;
    cin>>n;

    int a[n];
    inputa(a,n,0);
    int ans=0;
    auto p=minimumDp(a,0,n-1,ans);
    cout<<p.second<<endl;

    
    return 0;
}