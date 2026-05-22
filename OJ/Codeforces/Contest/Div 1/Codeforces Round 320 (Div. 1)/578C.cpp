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
#define input(v)       \
    for (auto &it : v) \
    cin >> it
#define inputa(a, n, ind)   \
    for (i = 0; i < n; i++) \
    cin >> a[i + ind]
#define output(v)      \
    for (auto &it : v) \
    cout << it << " "
#define outputa(a, n, ind)  \
    for (i = 0; i < n; i++) \
    cout << a[i + ind] << " "
#define outputl(v)     \
    for (auto &it : v) \
    cout << it << '\n'
#define outputal(a, n, ind) \
    for (i = 0; i < n; i++) \
    cout << a[i + ind] << '\n'

#define maxn (int)(2e5 + 100)
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

double f(int *a,int n,double t)
{
    double val = 0;
    int i;
    double d[n];
    for (i = 0; i < n; i++)
    {
        d[i]=1.0*a[i]-t;
    
    }

    double mx=0,mn=0;
    double sum1=0,sum2=0;
    for (i = 0; i < n; i++)
    {
        sum1+=d[i];
        mx=max(mx,sum1);
        sum2+=d[i];
        mn=min(mn,sum2);
      
        if(sum1<0)
        {
            sum1=0;
        }
        if(sum2>0)sum2=0;
    }
    val=max(mx,abs(mn));


    return val;
}

double ternary_search_minimum_doubles(int *a,int n,double l, double r)
{
    for (int i = 0; i < 100; i++)
    {
        double m1 = l + (r - l) / 3.0;
        double m2 = r - (r - l) / 3.0;

        if (f(a,n,m1) > f(a,n,m2))
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

    int n;
    cin >> n;
    int a[n + 1];
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    double x=ternary_search_minimum_doubles(a,n,-10000.0,10000.0);
    
    double ans=f(a,n,x);
    cout<<fixed<<setprecision(16)<<ans<<endl;

    return 0;
}