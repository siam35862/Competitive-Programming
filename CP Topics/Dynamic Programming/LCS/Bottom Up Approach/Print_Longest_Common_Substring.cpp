#include <bits/stdc++.h>
using namespace std;
string lcs(string &a, string &b, int n, int m, vector<vector<int>> &siam) // substring
{
    int i, j;
    int mx = 0;
    int mxi = -1, mxj = -1;
    string ans;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                siam[i][j] = siam[i - 1][j - 1] + 1;
            else
                siam[i][j] = 0;
            if (siam[i][j] > mx)
            {
                mx = siam[i][j];
                mxi = i;
                mxj = j;
            }  
        }
    }
    if (mxi != -1)
    {
        for (i = mxi, j = mxj; i >= 1 && j >= 1; i--, j--)
        {
            if (siam[i][j] != 0)
                ans.push_back(a[i - 1]);
            else
                break;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
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
        vector<vector<int>> siam(n + 1, vector<int>(m + 1, 0));
        int i, j;
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= m; j++)
                siam[i][j] = 0;
        }
        string ans = lcs(a, b, n, m, siam);
        if (ans.size() == 0)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}