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
#define inputa(a,n,ind) for(int i=0;i<n;i++)cin>>a[i+ind]
#define output(v) for(auto &it:v)cout<<it<<" "
#define outputa(a,n,ind) for(int i=0;i<n;i++)cout<<a[i+ind]<<" "
#define outputl(v) for(auto &it:v)cout<<it<<'\n'
#define outputal(a,n,ind) for(int i=0;i<n;i++)cout<<a[i+ind]<<'\n'

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
    int n;
    cin>>n;
    int one=0,two=0,three=0;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x==1)one++;
        else if(x==2)two++;
        else three++;
    }
    double dp[305][305][305]={};

  

    for(int k=0;k<=three;k++)
    {
        for(int j=0;j<=two+three;j++)
        {
            for(int i=0;i<=one+two+three;i++)
            {
                if(i==0&&j==0&&k==0)continue;

                dp[i][j][k]=n;
                if(i>0)dp[i][j][k]+=dp[i-1][j][k]*i;
                if(j>0)dp[i][j][k]+=dp[i+1][j-1][k]*j;
                if(k>0)dp[i][j][k]+=dp[i][j+1][k-1]*k;
                dp[i][j][k]/=(i+j+k);
               
            }
        }
    }
    cout<<fixed<<setprecision(10)<<dp[one][two][three]<<endl;
    
    return 0;
}