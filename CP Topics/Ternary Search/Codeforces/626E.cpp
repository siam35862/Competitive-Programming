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
pair<int,int> f(int *psum,int *a,int n,int ind,int x)
{
    
    int med=a[ind];
    int sum=a[ind]+psum[ind]-psum[ind-x]+psum[n]-psum[n-x];
    int denum=2*x+1;
    int num=sum-med*denum;
    return {num,denum};
}

int ternary_search_maximum(int *psum,int *a,int n,int ind,int l, int r)
{
    while (l < r)
    {
        int m1 = (l + r) / 2;
        int m2 = m1 + 1;
        auto p1=f(psum,a,n,ind,m1);
        auto p2=f(psum,a,n,ind,m2);
        if ( p1.first*p2.second< p2.first*p1.second)
            l = m2;
        else
            r = m1;
    }
    return l;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,i;

    cin >> n;
    int a[n + 1];
    int psum[n+1];
    psum[0]=0;
    inputa(a,n,0);
    sort(a,a+n);
    for (i = 0; i < n; i++)
    {
        
        psum[i+1]=psum[i]+a[i];

    }

    
    pair<int,int> p1={0,1};
    int x=0,ind=0;
    for(i=1;i<n-1;i++)
    {
        int l=1;
        int r=min(i-0,n-i-1);
        int xx=ternary_search_maximum(psum,a,n,i,l,r);
        auto p2=f(psum,a,n,i,xx);
        if(p1.first*p2.second< p2.first*p1.second)
        {
            p1=p2;
            ind=i;
            x=xx;

        }
    }
    //cout<<skewness<<endl;
    cout<<2*x+1<<endl;
    for(i=ind-x;i<=ind;i++)cout<<a[i]<<" ";
    for(i=n-x;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;


    
    return 0;
}