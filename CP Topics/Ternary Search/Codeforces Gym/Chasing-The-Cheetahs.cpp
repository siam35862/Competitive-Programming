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
double f(double *time, double *velocity,int n,double x)
{
    double val = 0;
    double mn=INT64_MAX;
    double mx=INT64_MIN;
    int i;
    double v=0;
    for(i=0;i<n;i++)
    {
        v=(x-time[i])*velocity[i];
        if(v>mx)mx=v;
        if(v<mn)mn=v;
    }
    val=mx-mn;
    return val;
}

double ternary_search_minimum_doubles(double *time, double *velocity,int n,double l, double r)
{
    for (int i = 0; i < 50; i++)
    {
        double m1 = l + (r - l) / 3.0;
        double m2 = r - (r - l) / 3.0;

        if (f(time,velocity,n,m1) > f(time,velocity,n,m2))
            l = m1;
        else
            r = m2;
    }
    return (l + r) / 2.0;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;

    for (int cs = 1; cs <= t; )
    {
        //cout << "Case " << cs << ": ";
        int n, m, i, j, k;
        cin>>n;
        if(n==0)break;
        double time[n],velocity[n];
        double tt=0;
        for (i = 0; i < n; i++)
        {
            cin>>time[i]>>velocity[i];
            tt=max(tt,time[i]);
        }

        double time_=ternary_search_minimum_doubles(time,velocity,n,tt,tt+1e6);
        double ans=f(time,velocity,n,time_);
        cout<<fixed<<setprecision(6)<<ans<<endl;

        
    }

    
    return 0;
}