#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, w;
    cin >> n >> w;
    int v = 0;
    int wt[n], val[n], i, j;
    for (i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
        v += val[i];
    }
    int siam[n + 1][v + 1] = {};
    for(i=0;i<=v;i++)siam[0][i]=INT_MAX;
    for(i=0;i<=n;i++)siam[i][0]=0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= v; j++)
        {
            if (val[i-1] <= j)
            {
                siam[i][j] =min(siam[i-1][j], wt[i - 1] + siam[i - 1][j - val[i - 1]]);
            }
            else
                siam[i][j] = siam[i - 1][j];
        }
    }
    int ans = 0;
    for (i = 1; i <= v; i++)
      {  if (siam[n][i] <= w)
            ans = i;          
      }
    cout << ans << endl;
}

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/
