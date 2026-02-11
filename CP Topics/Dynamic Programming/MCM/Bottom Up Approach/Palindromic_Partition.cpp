#include <bits/stdc++.h>
using namespace std;
int pp(string &s)
{
    int n = s.size();
    int siam[n][n];
    bool pal[n][n];
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        pal[i][i] = true;
        siam[i][i] = 0;
    }
    int len;
    for (len = 2; len <= n; len++)
    {
        for (i = 0, j = i + len - 1; j < n; j++, i++)
        {
            if (len == 2)
            {
                pal[i][j] = s[i] == s[j];
            }
            else
            {
                pal[i][j] = s[i] == s[j] && pal[i + 1][j - 1];
            }
            if (pal[i][j] == true)
                siam[i][j] = 0;
            else
            {

                siam[i][j] = INT_MAX;
                for (k = i; k < j; k++)
                {
                    siam[i][j] = min(siam[i][j], 1 + siam[i][k] + siam[k + 1][j]);
                }
            }
        }
    }
    return siam[0][n-1];
}
int32_t main()
{
    string s;
    cin >> s;
    int ans=pp(s);
    cout<<ans<<endl;
}