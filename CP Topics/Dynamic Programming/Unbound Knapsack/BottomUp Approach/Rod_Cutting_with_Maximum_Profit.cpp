#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> siam;
int maximizeProfit(int n, int *price)
{
     int i, j;
     for (i = 1; i <= n; i++)
     {
          for (j = 1; j <= n; j++)
          {
               if(i<=j)
               {
                    siam[i][j]=max(siam[i-1][j],price[i]+siam[i][j-i]);
               }
               else siam[i][j]=siam[i-1][j];
          }
     }
     return siam[n][n];
}
signed main()
{
     int n;
     cin >> n;
     int price[n + 1] = {};
     int i;
     for (i = 1; i <= n; i++)
     {
          cin >> price[i];
     }
     siam.resize(n + 1, vector<int>(n + 1, 0));
     int ans = maximizeProfit(n, price);
     cout << ans << endl;
}
