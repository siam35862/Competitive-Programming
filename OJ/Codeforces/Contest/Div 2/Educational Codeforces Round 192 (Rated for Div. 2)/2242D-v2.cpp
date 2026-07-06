#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define endl '\n'
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define rev(v) reverse(v.begin(), v.end())
#define input(v)       \
    for (auto &it : v) \
    cin >> it
#define inputa(a, n, ind)       \
    for (int i = 0; i < n; i++) \
    cin >> a[i + ind]
#define output(v)      \
    for (auto &it : v) \
    cout << it << " "
#define outputa(a, n, ind)      \
    for (int i = 0; i < n; i++) \
    cout << a[i + ind] << " "
#define outputl(v)     \
    for (auto &it : v) \
    cout << it << '\n'
#define outputal(a, n, ind)     \
    for (int i = 0; i < n; i++) \
    cout << a[i + ind] << '\n'

#define maxn (int)(5e3 + 5)
#define M 998244353
#define inf 1e18

template <class T>
struct comparator
{
    bool operator()(const T &a, const T &b) const
    {
        return a < b;
    }
};

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
using ordered_setd = tree<T, null_type, greater<T>, rb_tree_tag,
                          tree_order_statistics_node_update>;

// Updated DP parameter to 4D vector
int dp_s(int i, int j, string &a, string &b, vector<vector<vector<vector<int>>>> &dp, int *p, int *q)
{
    if (i == 0 || j == 0)
        return 0;
        
    // Checked with 4D state
    if (dp[i][j][a[i - 1] - '0'][b[j - 1] - '0'] != -1)
        return dp[i][j][a[i - 1] - '0'][b[j - 1] - '0'];
     
    if (a[i - 1] == b[j - 1])
    {
        int val = dp_s(i - 1, j - 1, a, b, dp, p, q);
        if (val > 0 || (i == 1 && j == 1) || (i == 1 && q[j - 2]) || (j == 1 && p[i - 2]))
        {
            dp[i][j][a[i - 1] - '0'][b[j - 1] - '0'] = max(dp[i][j][a[i - 1] - '0'][b[j - 1] - '0'], 1 + val);
        }
        else
            dp[i][j][a[i - 1] - '0'][b[j - 1] - '0'] = 0;
    }
    else
    {
        if (i > 1)
        {
            char ch1 = a[i - 2];
            int ch = (a[i - 1] - '0') + a[i - 2] - '0';
            ch %= 10;
            char ch2 = '0';
            ch2 += ch;
            a[i - 2] = ch2;
            int val = dp_s(i - 1, j, a, b, dp, p, q);
            dp[i][j][a[i - 1] - '0'][b[j - 1] - '0'] = max(dp[i][j][a[i - 1] - '0'][b[j - 1] - '0'], val);
            a[i - 2] = ch1;
        }
        if (j > 1)
        {
            char ch1 = b[j - 2];
            int ch = (b[j - 1] - '0') + b[j - 2] - '0';
            ch %= 10;
            char ch2 = '0';
            ch2 += ch;
            b[j - 2] = ch2;
            int val = dp_s(i, j - 1, a, b, dp, p, q);
            dp[i][j][a[i - 1] - '0'][b[j - 1] - '0'] = max(dp[i][j][a[i - 1] - '0'][b[j - 1] - '0'], val);
            b[j - 2] = ch1;
        }
    }
    
    return dp[i][j][a[i - 1] - '0'][b[j - 1] - '0'];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        int n, m, i, j, k;
        string a, b;
        cin >> a >> b;
        n = a.length();
        m = b.length();
        
        // Initialized 4D DP table of size (n+1) x (m+1) x 10 x 10
        vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(m + 1, vector<vector<int>>(10, vector<int>(10, -1))));

        int p[n] = {}, q[m] = {}; // Fixed: q allocated with size m instead of n
        for (i = 0; i < n; i++)
        {
            if (a[i] == '0') p[i] = 1;
            else break;
        }
        for (i = 0; i < m; i++)
        {
            if (b[i] == '0') q[i] = 1;
            else break;
        }

        int ans = dp_s(n, m, a, b, dp, p, q);
        if (ans == 0)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}