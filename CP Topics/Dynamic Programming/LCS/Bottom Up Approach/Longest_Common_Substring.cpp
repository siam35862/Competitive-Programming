#include <bits/stdc++.h>
using namespace std;
int lcs(string &a, string &b, int n, int m, vector<vector<int>> &siam)//substring
{
    int i,j;
    int ans=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])siam[i][j]=siam[i-1][j-1]+1;
            else siam[i][j]=0;
            ans=max(ans,siam[i][j]);
        }
    }
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
        int ans=lcs(a, b, n, m, siam);
        cout << ans << endl;
    }
}