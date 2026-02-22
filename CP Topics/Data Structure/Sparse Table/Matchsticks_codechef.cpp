#include<bits/stdc++.h>
using namespace std;
#define int long long
int lg[200005];
void log()
{
    lg[0]=0;
    lg[1]=0;
    for(int i=2;i<=200000;i++)lg[i]=lg[i/2]+1;
}
void precomputation(vector<vector<int>>&st1,vector<vector<int>>&st2,int *a,int n,int k)
{
    int i;
    for(i=0;i<n;i++)
    {
        st1[0][i]=a[i];
         st2[0][i]=a[i];

    }
    for(i=1;i<=k;i++)
    {
        int j;
        for(j=0;j+(1<<i)<=n;j++)
        {
            st1[i][j]=min(st1[i-1][j],st1[i-1][j+(1<<(i-1))]);
            st2[i][j]=max(st2[i-1][j],st2[i-1][j+(1<<(i-1))]);
        }
    }
}
int range_min(vector<vector<int>>&st,int l,int r)
{
    int i=lg[r-l+1];
    return min(st[i][l],st[i][r-(1<<i)+1]);
}
int range_max(vector<vector<int>>&st,int l,int r)
{
    int i=lg[r-l+1];
    return max(st[i][l],st[i][r-(1<<i)+1]);
}
signed main()
{      
    log();
    int n,q;
    cin>>n;
    int m=lg[n]+2;
    int a[n];
    int i;
    for(i=0;i<n;i++)cin>>a[i];
    vector<vector<int>>st1(m+1,vector<int>(n,0)),st2(m+1,vector<int>(n,0)); 
    precomputation(st1,st2,a,n,m);
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
       
        int mn=range_min(st1,l,r);
        int mx=range_max(st2,l,r);
        float ans=mn+(mx-mn)/2.0;
        if(l>0)ans=max(ans,float(mn+range_max(st2,0,l-1)));
        if(r<n-1)ans=max(ans,float(mn+range_max(st2,r+1,n-1)));
        cout<<fixed<<setprecision(1)<<ans<<endl;
    }
    return 0; 
}