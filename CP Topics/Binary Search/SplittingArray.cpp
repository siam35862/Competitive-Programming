#include <bits/stdc++.h>

using namespace std;
#define int long long
#define d long double
int n,k;

bool f(int *a,int sum)
{
    int c=1;
    int temp=0,i;
    for(i=0;i<n;i++)
    {
        if(temp+a[i]<=sum)
        {
            temp+=a[i];
        }
        else 
        {
            c++;
            temp=a[i];
        }
    }
    return c<=k;
}
signed main()
{
    cin >>n>>k;
    int a[n];
    int i;
    int ll=0,sum=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        ll=max(a[i],ll);
        sum+=a[i];
    }
    int l=ll,r=sum,ans;
    ans=r;
    i=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(f(a,mid))
        {
            ans=min(mid,ans);
            r=mid-1;
        }
        else l=mid+1;
        i++;
    }
    
    cout<<ans<<endl;
}