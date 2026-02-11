#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
// using namespace __gnu_pbds;
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, w;
    cin >> n >> w;
    int siam[n + 1][w + 1] = {};
    int a[n + 1] = {}, b[n + 1] = {}, i, j;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= w; j++)
        {
            if (a[i] <= j)
            {
                siam[i][j] = max(b[i] + siam[i - 1][j - a[i]], siam[i - 1][j]);
            }
            else
                siam[i][j] = siam[i - 1][j];
        }
    }
    cout << siam[n][w] << endl;
    return 0;
}

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/

//time complexity O(n*w)

