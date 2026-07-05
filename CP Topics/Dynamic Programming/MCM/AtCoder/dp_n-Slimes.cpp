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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a[n + 1];
    inputa(a, n, 1);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, inf)), cost(n + 1, vector<int>(n + 1, inf));

    int i, j;
    for (int k = 0; k < n; k++)
    {
        for (i = 1; i <= n - k; i++)
        {
            dp[i][i] = a[i];
            cost[i][i] = 0;

            for (int j = i; j < i + k && j < n; j++)
            {
                if (dp[i][j] + dp[j + 1][i + k] + cost[i][j] + cost[j + 1][i + k] < cost[i][i + k])
                {
                    dp[i][i + k] = dp[i][j] + dp[j + 1][i + k];
                    cost[i][i + k] = cost[i][j] + cost[j + 1][i + k] + dp[i][i + k];
                }
            }
                }
    }

    cout << cost[1][n] << endl;

    return 0;
}