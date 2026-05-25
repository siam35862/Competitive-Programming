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
#define inputa(a, n, ind)   \
    for (i = 0; i < n; i++) \
    cin >> a[i + ind]
#define output(v)      \
    for (auto &it : v) \
    cout << it << " "
#define outputa(a, n, ind)  \
    for (i = 0; i < n; i++) \
    cout << a[i + ind] << " "
#define outputl(v)     \
    for (auto &it : v) \
    cout << it << '\n'
#define outputal(a, n, ind) \
    for (i = 0; i < n; i++) \
    cout << a[i + ind] << '\n'
#define forl(i, l, r) for (i = l; i <= r; i++)
#define forlrv(i, r, l) for (i = r; i >= l; i--)

#define maxn (int)(2e5 + 100)
#define M 998244353

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

double dp[305][305][305];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    int one = 0, two = 0, three = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            one++;
        if (a[i] == 2)
            two++;
        if (a[i] == 3)
            three++;
    }
    int j, k;
    // dp[one][two][three]=1;
    forl(k, 0, n)
    {
        forl(j, 0, n)
        {
            forl(i, 0, n)
            {
                if (i == 0 && j == 0 && k == 0)
                    continue;
                if (i + j + k > n)
                    continue;
                dp[i][j][k] = n;
                if (i > 0)
                    dp[i][j][k] += dp[i - 1][j][k] * i;
                if (j > 0)
                    dp[i][j][k] += dp[i + 1][j - 1][k] * j;
                if (k > 0)
                    dp[i][j][k] += dp[i][j + 1][k - 1] * k;
                dp[i][j][k] /= 1.0 * (i + j + k);
            }
        }
    }

    double ans = dp[one][two][three];
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}