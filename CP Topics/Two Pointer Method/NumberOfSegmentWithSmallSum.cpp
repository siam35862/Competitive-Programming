#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n,s;
    cin>>n>>s;
    int a[n],i;
    for(i=0;i<n;i++)cin>>a[i];
    int sum=0;
    int ans=0,l=0;
    for(int r=0;r<n;r++)
    {
        sum+=a[r];
        while(sum>s)
        {
            sum-=a[l];
            l++;
        }
        ans+=r-l+1;
    }
    cout<<ans<<endl;
    
}