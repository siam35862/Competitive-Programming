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
#define M (int)(1e9 + 7)
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

    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0)), psum(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i <= k; i++)
        psum[0][i] = 1;
    int i, j;
    int a[n + 1];
    inputa(a, n, 1);
    for (i = 1; i <= n; i++)
    {
        //psum[i][0]=1;
        for (j = 0; j <= k; j++)
        {
            int pos = max(0LL, j - a[i]) - 1;
            if (pos < 0)
                dp[i][j] = psum[i - 1][j];
            else
                dp[i][j] = (psum[i - 1][j] - psum[i - 1][pos] + M) % M;

            psum[i][j] = ((j==0)?1:psum[i][j - 1] + dp[i][j]) % M;
        }
        
    }
    cout << dp[n][k] << endl;

    return 0;
}