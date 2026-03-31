#include<bits/stdc++.h>
using namespace std;

#define int long long 


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("div7.in","r",stdin);
    //  freopen("div7.out","w",stdout);

    int n;
    cin>>n;
    int a[n+1];
    int p[n+1]={};
    int ans=0;
    map<int,int>mp;
    mp[0]=0;
    int i;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        p[i]=p[i-1]+a[i];
        p[i]%=7;

        if(mp.find(p[i])==mp.end())mp[p[i]]=i;
        ans=max(ans,i-mp[p[i]]);
    }
    cout<<ans<<endl;
}
