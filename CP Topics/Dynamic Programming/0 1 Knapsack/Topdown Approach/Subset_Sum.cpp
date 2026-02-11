#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
    n * s must be less than or equal 1e8
*/
vector<vector<bool>> siam;
bool isSubsetSum(int n, int s, int *a)
{
    int i,j;
    for(i=0;i<=n;i++)siam[i][0]=true;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=s;j++)
        {
            if(a[i-1]<=j)siam[i][j]=siam[i-1][j]||siam[i-1][j-a[i-1]];
            else siam[i][j]=siam[i-1][j];
        }
    }
    return siam[n][s];
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,s;
    cin>>n>>s;
    int a[n],i;
    for(i=0;i<n;i++)cin>>a[i];
    siam.resize(n+1);
    for(i=0;i<=n;i++)siam[i].resize(s+1,0);
    bool ans=isSubsetSum(n,s,a);
    if(ans)cout<<"YES\n";
    else cout<<"NO\n";

}

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/