#include <bits/stdc++.h>
using namespace std;
int lcs(string &a, string &b, int n, int m, vector<vector<int>> &siam) // subsequence
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (siam[n][m] != -1)
        return siam[n][m];
    if (a[n - 1] == b[m - 1])
    {

        siam[n][m] = 1 + lcs(a, b, n - 1, m - 1, siam);
    }
    else
        siam[n][m] = max(lcs(a, b, n - 1, m, siam), lcs(a, b, n, m - 1, siam));

    return siam[n][m];
}
void make_lcs(int n, int m, string &a, string &b, string &s, vector<vector<int>> &siam, set<string> &ans, map<pair<pair<int, int>, pair<int, int>>, int> &visited)
{

    if (n == 0 || m == 0)
    {
        return;
    }
    if (a[n - 1] == b[m - 1])
    {
        s += a[n - 1];
        if (siam[n][m] == 1)
        {
            if (s.size() > 0)
            {
                string a = s;
                reverse(a.begin(), a.end());
                ans.insert(a);
            }
        }
        else
        {
            if (visited[{{n, m}, {n - 1, m - 1}}] == 0)
                make_lcs(n - 1, m - 1, a, b, s, siam, ans, visited);
            visited[{{n, m}, {n - 1, m - 1}}] = 1;
        }
        s.pop_back();
    }
    else
    {
        if (siam[n][m] > 0)
        {
            if (siam[n - 1][m] > siam[n][m - 1])
            {
                if (visited[{{n, m}, {n - 1, m}}] == 0)
                    make_lcs(n - 1, m, a, b, s, siam, ans, visited);
                visited[{{n, m}, {n - 1, m}}] = 1;
            }
            else if (siam[n - 1][m] < siam[n][m - 1])
            {
                if (visited[{{n, m}, {n, m - 1}}] == 0)
                    make_lcs(n, m - 1, a, b, s, siam, ans, visited);
                visited[{{n, m}, {n, m - 1}}] = 1;
            }
            else
            {
                if (visited[{{n, m}, {n - 1, m}}] == 0)
                    make_lcs(n - 1, m, a, b, s, siam, ans, visited);
                visited[{{n, m}, {n - 1, m}}] = 1;
                if (visited[{{n, m}, {n, m - 1}}] == 0)
                    make_lcs(n, m - 1, a, b, s, siam, ans, visited);
                visited[{{n, m}, {n, m - 1}}] = 1;
            }
        }
    }
}
void lcs(string &a, string &b)
{
    int n = a.size();
    int m = b.size();
    vector<vector<int>> siam(n + 1, vector<int>(m + 1, -1));
    map<pair<pair<int, int>, pair<int, int>>, int> visited;
    int i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
            siam[i][j] = -1;
    }
    lcs(a, b, n, m, siam);
    set<string> ans;

    string s;
    make_lcs(n, m, a, b, s, siam, ans, visited);

    int l = ans.size();
    if (l > 0)
    {
        cout << "All possible longest common subsequence: \n";
        cout << l << endl;
        for (auto it : ans)
            cout << it << endl;
        cout << "Lexicographically smallest subsequence:\n";
        cout << *ans.begin() << endl;
    }
    else
        cout << "There is no common subsequence.\n";
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
        lcs(a, b);
    }
}