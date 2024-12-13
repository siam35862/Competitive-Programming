#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
// using namespace __gnu_pbds;
using namespace std;
#define int unsigned long long
#define M 1000000007

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    cin >> n >> s;
    int a[n+1],i,j;
    bool siam[n+1][s+1];
    for(i=1;i<=n;i++)cin>>a[i];
    for(j=0;j<=s;j++)siam[0][j]=false;
    for(i=0;i<=n;i++)siam[i][0]=true;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=s;j++)
        {
            if(a[i]<=j)
            {
                siam[i][j]=siam[i-1][j]||siam[i-1][j-a[i]];
            }
            else siam[i][j]=siam[i-1][j];
        }
    }
    if(siam[n][s])cout<<"Yes\n";
    else cout<<"No\n";
}

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/
