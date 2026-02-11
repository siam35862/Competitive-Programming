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
    int ans=INT64_MAX,l=0;
    for(int r=0;r<n;r++)
    {
        sum+=a[r];
        while(sum-a[l]>=s)
        {
            sum-=a[l];
            l++;
        }
        if(sum>=s)ans=min(ans,r-l+1);
    }
    if(ans==INT64_MAX)cout<<-1<<endl;
    else cout<<ans<<endl;
    
}