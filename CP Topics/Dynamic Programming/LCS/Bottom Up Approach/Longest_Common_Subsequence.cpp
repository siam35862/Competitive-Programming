#include <bits/stdc++.h>
using namespace std;
int lcs(string &a, string &b, int n, int m, vector<vector<int>> &siam) // subsequence
{
    int i, j;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                siam[i][j] = siam[i - 1][j - 1] + 1;
            else
                siam[i][j] = max(siam[i][j - 1], siam[i - 1][j]);
        }
    }
    return siam[n][m];
}
int32_t main()
{
    int t;

    int n, m;
    string a, b, c;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        n = c.size();
        m = n;
        string aa = a + b;
        string bb = b + a;
        vector<vector<int>> siam(n + 1, vector<int>(m + 1, 0));
        int i, j;
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= m; j++)
                siam[i][j] = 0;
        }
        int ans1 = lcs(aa, c, n, m, siam);
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= m; j++)
                siam[i][j] = 0;
        }
        int ans2 = lcs(bb, c, n, m, siam);
        cout << min(ans1,ans2) << endl;
    }
}