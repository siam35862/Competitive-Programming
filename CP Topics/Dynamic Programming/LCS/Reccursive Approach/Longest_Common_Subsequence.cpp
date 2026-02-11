#include <bits/stdc++.h>
using namespace std;

int lcs(string &a, string &b, int n, int m, vector<vector<int>> &siam)//subsequence
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (siam[n][m] != -1)
        return siam[n][m];
    if (a[n - 1] == b[m - 1])
        return siam[n][m] = 1 + lcs(a, b, n - 1, m - 1, siam);
    else
        return siam[n][m] = max(lcs(a, b, n - 1, m, siam), lcs(a, b, n, m - 1, siam));
}
int32_t main()
{
    int t;

    int n, m;
    string a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        n = a.size();
        m = b.size();
        vector<vector<int>> siam(n + 1, vector<int>(m + 1, -1));
        int i, j;
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= m; j++)
                siam[i][j] = -1;
        }
        int ans = lcs(a, b, n, m, siam);
        cout << ans << endl;
    }
}