#include <bits/stdc++.h>
using namespace std;
// recursive approach failed to find all possible output
int lcs(string &a, string &b, int n, int m, vector<vector<int>> &siam) // substring
{
    int i, j;
    int ans = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                siam[i][j] = siam[i - 1][j - 1] + 1;
            else
                siam[i][j] = 0;
            ans = max(ans, siam[i][j]);
        }
    }
    return ans;
}
void make_lcs(int n, int m, string &a, string &b, string &s, vector<vector<int>> &siam)
{
    s += a[n - 1];
    if (siam[n][m] == 1)
        return;
    make_lcs(n - 1, m - 1, a, b, s, siam);
}

void lcs(string &a, string &b)
{
    int n, m;
    n = a.size();
    m = b.size();
    vector<vector<int>> siam(n + 1, vector<int>(m + 1, 0));
    int mx = lcs(a, b, n, m, siam);
    if (mx == 0)
    {
        cout << "There is no common substring.\n";
        return;
    }
    set<string> ans;
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {

            if (siam[i][j] == mx)
            {
                string s;
                make_lcs(i, j, a, b, s, siam);
                reverse(s.begin(),s.end());
                ans.insert(s);
            }
        }
    }

    int l = ans.size();
    cout << "All possible longest common substring: \n";
    cout << l << endl;
    for (auto it : ans)
        cout << it << endl;
    cout << "Lexicographically smallest substring:\n";
    cout << *ans.begin() << endl;
}
int32_t main()
{
    int t;

    string a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;

        lcs(a, b);
    }
}