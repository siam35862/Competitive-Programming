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

int ans=0;
void rec_dp(int i,int n,int count,int *a,double val)
{
   // cout<<i<<" "<<count<<endl;
     if(i==n)return;
     

    double p_val=val;
    double n_val=val+a[i];
    int flag=0;
    if((p_val>0&&n_val<0)||(p_val<0&&n_val>0))
    {
        flag=1;
        //cout<<"oka\n";
    }
    ans=max(ans,count+flag);
    rec_dp(i+1,n,count+flag,a,val+a[i]);

    n_val=val-a[i];
    flag=0;
    if((p_val>0&&n_val<0)||(p_val<0&&n_val>0))
    {
        flag=1;
    }
    ans=max(ans,count+flag);
    rec_dp(i+1,n,count+flag,a,val-a[i]);
    
     
     
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,i,j;
    cin>>n;


    int a[n + 1];
    
    
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    double val=0.5;
    rec_dp(0,n,0,a,val);
    cout<<ans<<endl;
    
    return 0;
}