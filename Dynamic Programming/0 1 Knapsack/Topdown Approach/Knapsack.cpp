#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
time complexity: O(n*w)
n*w must be less than 1e8
*/
vector<vector<int>>siam;
int knapsack(int n,int w,int *val,int *wt)
{
    int i,j;
    siam.resize(n+1);
    for(i=0;i<=n;i++)siam[i].resize(w+1,0);
     for(i=1;i<=n;i++)
     {
        for(j=1;j<=w;j++)
        {
            if(wt[i-1]<=j)
            {
                siam[i][j]=max(val[i-1]+siam[i-1][j-wt[i-1]],siam[i-1][j]);
            }
            else siam[i][j]=siam[i-1][j];
        }
     }
     return siam[n][w];
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int  n,w;
    int i,j;
    cin>>n>>w;
    int val[n],wt[n];
    for(i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
    int ans=knapsack(n,w,val,wt); 
    cout<<ans<<endl;
}

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/