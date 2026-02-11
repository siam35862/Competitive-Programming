#include <bits/stdc++.h>
using namespace std;
int pp(string &s)
{
    int n = s.size();
    int siam[n];
    bool pal[n][n];
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        pal[i][i] = true;
        siam[i] = INT_MAX;
    }
    siam[0] = 0;
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
        }
    }
    for(i=1;i<n;i++)
    {
        if(pal[0][i]==true)siam[i]=0;
        else
        {
            for(j=i;j>=1;j--)
            {
                if(pal[j][i])
                {
                    siam[i]=min(siam[i],1+siam[j-1]);
                }
            }
        }
    }

    return siam[n - 1];
}
int32_t main()
{
    string s;
    cin >> s;
    int ans = pp(s);
    cout << ans << endl;
}