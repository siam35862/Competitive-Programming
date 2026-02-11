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
    int a[n], b[n];
    int j;
    for (j = 0; j < n; j++)
    {
        cin >> a[j] >> b[j];
    }
    int ans = 0;
    for (int mask = 0; mask < (1LL << n); mask++)
    {
        int sumofw = 0, sumofv = 0;
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1LL << i)))
            {
                sumofv += b[i];
                sumofw += a[i];
            }
        }
        if (sumofw <= w)
            ans = max(ans, sumofv);
    }
    cout << ans << endl;
    return 0;
}

/*
  Md. Siam Ahmed
  CSE, Khulna University
*/
// time complexity O(2^n)
