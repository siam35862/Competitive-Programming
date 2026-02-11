#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int mxi = -1, mxj = -1;
int lcs(string &a, string &b, int n, int m, vector<vector<int>> &siam) // substring
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (siam[n][m] != -1)
        return siam[n][m];
    if (a[n - 1] == b[m - 1])
        siam[n][m] = 1 + lcs(a, b, n - 1, m - 1, siam);
    else
    {
        siam[n][m] = 0;
        lcs(a, b, n - 1, m, siam);
        lcs(a, b, n, m - 1, siam);
    }
    if (siam[n][m] > ans)
    {
        ans = siam[n][m];
        mxi = n;
        mxj = m;
    }
    return siam[n][m];
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
        mxi = -1, mxj = -1;
        lcs(a, b, n, m, siam);

        string ans;
        if (mxi != -1)
        {
            for (i = mxi, j = mxj; i >= 1 && j >= 1; i--, j--)
            {
                if (siam[i][j] > 0)
                    ans.push_back(a[i - 1]);
                else
                    break;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}