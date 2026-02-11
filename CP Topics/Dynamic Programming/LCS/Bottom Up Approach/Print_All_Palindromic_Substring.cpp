#include <bits/stdc++.h>
using namespace std;
void lcs(string s)
{
    int n = s.size();
    vector<vector<int>> siam(n, vector<int>(n, 0));
    multiset<pair<int, string>> ans;
    int i, j;
    for (i = 0; i < n; i++)
    {
        siam[i][i] = 1;
        ans.insert({1, s.substr(i, 1)});
    }
    int maxlen = 1;
    int cnt = n;
    for (i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            ans.insert({2, s.substr(i, 2)});
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
                ans.insert({maxlen, s.substr(i, maxlen)});
            }
        }
    }

    cout << "All Palindromic Substring:\n";
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it.second << endl;
    cout << endl;
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