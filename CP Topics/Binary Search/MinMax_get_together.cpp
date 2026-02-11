#include <bits/stdc++.h>

using namespace std;
#define int long long
#define d long double
int n;
d x[100001],v[100001];
bool f(d t)
{
    
    d l=x[0]-t*v[0],r=x[0]+t*v[0];
    int i;
    for(i=0;i<n;i++)
    {
        l=max(l,x[i]-t*v[i]);
        r=min(r,x[i]+v[i]*t);           
        if(l>r)return false;
    }
    return l<=r;
}
signed main()
{
    cin >>n;
    //int a[n];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>x[i]>>v[i];
    }
    d l=0,r=1e9,ans;
    ans=r;
    i=0;
    while(i<100)
    {
        d mid=(l+r)/2;
        if(f(mid))
        {
            ans=min(mid,ans);
            r=mid;
        }
        else l=mid;
        i++;
    }
   
    cout<<fixed<<setprecision(20)<<ans<<endl;
}