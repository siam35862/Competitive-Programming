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
void precomputation(vector<vector<int>>&st,int *a,int n,int k)
{
    int i;
    for(i=0;i<n;i++)
    {
        st[0][i]=a[i];
    }
    for(i=1;i<=k;i++)
    {
        int j;
        for(j=0;j+(1<<i)<=n;j++)
        {
            st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
}
int range_min(vector<vector<int>>&st,int l,int r)
{
    int i=lg[r-l+1];
    return min(st[i][l],st[i][r-(1<<i)+1]);
}
signed main()
{      
    log();
    int n,q;
    cin>>n>>q;
    int m=lg[n]+2;
    int a[n];
    int i;
    for(i=0;i<n;i++)cin>>a[i];
    vector<vector<int>>st(m+1,vector<int>(n,0)); 
    precomputation(st,a,n,m);
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        int ans=range_min(st,l,r);
        cout<<ans<<endl;
    } 
}