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

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        //cout << "Case " << cs << ": ";
        int n, m, i, j, k;
        cin>>n>>m>>k;
        int a[n][m];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        string s[n];
        for(i=0;i<n;i++)cin>>s[i];
        int psum[n+1][m+1]={};
         int D=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1];
                psum[i][j]+=(s[i-1][j-1]=='1')?1:-1;
                D+=(s[i-1][j-1]=='1')?a[i-1][j-1]:-a[i-1][j-1];
            }
        }
       
    
        if(D==0)cout<<"YES\n";
        else
        {
            int gcd=0;
            for(i=k;i<=n;i++)
            {
                for(j=k;j<=m;j++)
                {
                    int val=psum[i][j]-psum[i-k][j]-psum[i][j-k]+psum[i-k][j-k];
                    
                    gcd=__gcd(val,gcd);
                    //cout<<val<<" ";
                }
                //cout<<endl;
            }
           // cout<<gcd<<" ";
            if(gcd==0)cout<<"NO\n";
            else if(D%gcd==0)cout<<"YES\n";
            else cout<<"NO\n";
        }
        
        
    }
    
    return 0;
}