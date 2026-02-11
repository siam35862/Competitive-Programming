#include <bits/stdc++.h>
using namespace std;
void lcs(string s)
{
    int n = s.size();
    vector<vector<int>> siam(n, vector<int>(n, 0));
    int i, j;
    for (i = 0; i < n; i++)
        siam[i][i] = 1;
    int maxlen = 1;
    int cnt = n;
    for (i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            siam[i][i + 1] = 1;
            maxlen = 2;
            cnt++;
        }
    }

    for (int k = 3; k <= n; k++)
    {
        for (i = 0; i <= n - k; i++)
        {
            j = i + k - 1;
            if (s[i] == s[j] && siam[i + 1][j - 1])
            {
                cnt++;
                siam[i][j] = 1;
                maxlen = k;
            }
        }
    }
    set<string> ans;
    if (maxlen == 1)
    {
        for (i = 0; i < n; i++)
            ans.insert(s.substr(i, 1));
    }
    else if (maxlen == 2)
    {
        for (i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                ans.insert(s.substr(i, 2));
            }
        }
    }
    else
    {
        for (i = 0; i <= n - maxlen; i++)
        {
            j = i + maxlen - 1;
            if (s[i] == s[j] && siam[i + 1][j - 1])
            {
                ans.insert(s.substr(i, maxlen));
            }
        }
    }
    cout << "The Number of all palindromic substring: " << cnt << endl;
    cout << "Longest All Palindromic Substring:\n";
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it << endl;
}
int32_t main()
{
    int t;

    string a, b;
    cin >> t;
    while (t--)
    {
        cin >> a;

        lcs(a);
    }
}