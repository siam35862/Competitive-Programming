#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],i;
    for(i=0;i<n;i++)cin>>a[i];
    int l=0,r=n-1;
    int ans=n;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(a[m]==m)l=m+1;
        else if(a[m]>m)
        {
            ans=m;
            r=m-1;
        }
    }
    cout<<ans<<endl;
}