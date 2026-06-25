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
#define inf 1e18

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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,k;
    cin>>n>>m>>k;

    int a[n+1],i;
    inputa(a,n,1);

    vector<int>diff(maxn+1,0);
    vector<int>diff2(maxn+1,0);
    int l[m+1],r[m+1],c[m+1];
    for(i=1;i<=m;i++)
    {
        
        cin>>l[i]>>r[i]>>c[i];
        
    }
    
    for(i=1;i<=k;i++)
    {
        int ll,rr;
        cin>>ll>>rr;
        diff2[ll]+=1;
        diff2[rr+1]-=1;
    }
    for(i=1;i<=m;i++)diff2[i]+=diff2[i-1];

    for(i=1;i<=m;i++)
    {
        diff[l[i]]+=c[i]*diff2[i];
        diff[r[i]+1]-=c[i]*diff2[i];
    }
    for(i=1;i<=n;i++)
    {
        diff[i]+=diff[i-1];
        a[i]+=diff[i];
        cout<<a[i]<<" ";
    }
    cout<<endl;

    
    return 0;
}