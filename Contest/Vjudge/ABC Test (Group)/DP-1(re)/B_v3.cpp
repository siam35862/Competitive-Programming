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

double dp[305][305][305], p[305][305][305];

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
    p[one][two][three] = 1;
    forlrv(k, n, 0)
    {
        forlrv(j, n, 0)
        {
            forlrv(i, n, 0)
            {
                if (i == 0 && j == 0 && k == 0)
                    continue;
                if (i + j + k > n)
                    continue;
                dp[i][j][k] += p[i][j][k] * n / (i + j + k);
                if (i > 0)
                {
                    dp[i - 1][j][k] += dp[i][j][k] * (i * 1.0 / (i + j + k));
                    p[i - 1][j][k] += p[i][j][k] * (i * 1.0 / (i + j + k));
                }
                if (j > 0)
                {
                    dp[i + 1][j - 1][k] += dp[i][j][k] * (j * 1.0 / (i + j + k));

                    p[i + 1][j - 1][k] += p[i][j][k] * (j * 1.0 / (i + j + k));
                }
                if (k > 0)
                {
                    dp[i][j + 1][k - 1] += dp[i][j][k] * (k * 1.0 / (i + j + k));
                    p[i][j + 1][k - 1] += p[i][j][k] * (k * 1.0 / (i + j + k));
                }
            }
        }
    }

    double ans = dp[0][0][0];
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}