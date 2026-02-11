#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>siam;
int maximizeProfit(int n,int m,int * price)
{
    if(n==0||m==0)return 0;
    if(siam[n][m]!=-1)return siam[n][m];
    if(n<=m)
    {
        return siam[n][m]=max(maximizeProfit(n-1,m,price),price[n]+maximizeProfit(n,m-n,price));
    }
    else return siam[n][m]=maximizeProfit(n-1,m,price);
}
signed main()
{
    int n;
    cin>>n;
    int price[n+1]={};
    int i;
    for(i=1;i<=n;i++)
    {
        cin>>price[i];
    }
    siam.resize(n+1,vector<int>(n+1,-1));
   
    int ans=maximizeProfit(n,n,price);
    cout<<ans<<endl;
}