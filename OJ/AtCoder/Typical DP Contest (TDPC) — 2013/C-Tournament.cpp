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

int32_t main()
{
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed<<setprecision(10);
    int k;
    cin >> k;
    int n = (1 << k);
    double dp[k+1][n]={};
    int i,j;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin>>a[i];
        dp[0][i]=1;
    }

    for(i=1;i<=k;i++)
    {
        for(j=0;j<n;j++)
        {
            double value=0;
            for(int kk=0;kk<n;kk++)
            {
                if((j>>i)==(kk>>i)&&(j>>(i-1)!=(kk>>(i-1))))
                {
                    value+=dp[i-1][kk]*(1.0/(1.0+pow(10,(a[kk]-a[j])/400.0)));
                   
                }
            }
           
            dp[i][j]=dp[i-1][j]*value;
        }
    }
    
    for(i=0;i<n;i++)
    {
        cout<<dp[k][i]<<"\n";
    }
    


    return 0;
}