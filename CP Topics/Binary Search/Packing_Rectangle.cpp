#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll   n,x,y;

bool isitfit(ll r)
{
    r-=min(x,y);
    return ((floor)(1.0*r/x)+(floor)(1.0*r/y))>=(n-1);
}
ll solve(ll r)
{
    ll l = 1;
ll mid;
    while (l < r)
    {
        mid=l+(r-l)/2;
        //cout<<mid<<endl;
        if(isitfit(mid)==false)l=mid+1;
        else r=mid;
        
    }
    return r;
}
signed main()
{

    cin >> n>>x>>y;
    ll  r=1;
    while (isitfit(r) == false)
    {
        r = r * 2;
    }
   // cout<<r<<endl;
    
    ll  ans=solve(r);
    cout<<fixed<<setprecision(0)<<ans<<endl;
}