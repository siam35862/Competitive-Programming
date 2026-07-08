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

#define maxn (int)(2e5 + 100)
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
int min_ops(int n, int *a, vector<vector<int>> &dp)
{
    if (n == 1)
        return 0;
    if (dp[n][a[n - 1]] != -1)
        return dp[n][a[n - 1]];
    int temp = a[n - 2];
    int res = inf;
    if (a[n - 1] == 0)
    {
        a[n - 2] = 1;
        res = min(res, 1 - temp + min_ops(n - 1, a, dp));
        a[n - 2] = 2;
        res = min(res, 2 - temp + min_ops(n - 1, a, dp));
    }
    else if (a[n - 1] == 1)
    {
        if (temp == 0)
            res = min(res, min_ops(n - 1, a, dp));
        a[n - 2] = 2;
        res = min(res, 2 - temp + min_ops(n - 1, a, dp));
    }
    else if (a[n - 1] == 2)
    {
        res = min(res, min_ops(n - 1, a, dp));
        a[n - 2] = 1;
        res = min(res, 1 - temp + min_ops(n - 1, a, dp));
    }
    a[n - 2] = temp;
    return dp[n][a[n - 1]] = res;
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
        // cout << "Case " << cs << ": ";
        int n, m, i, j, k;
        cin >> n;
        int a[n];
        inputa(a, n, 0);
        vector<vector<int>> dp(n + 2, vector<int>(3, -1));
        int temp = a[n - 1];
        int ans = min_ops(n, a, dp);
        a[n - 1] = 1;
        ans = min(ans, 1 - temp + min_ops(n, a, dp));
        a[n - 1] = 2;
        ans = min(ans, 2 - temp + min_ops(n, a, dp));
        cout << ans << endl;
    }
    return 0;
}