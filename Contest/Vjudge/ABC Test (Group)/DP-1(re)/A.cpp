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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    double a[n];
    int i;

    inputa(a, n, 0);

    double dp_new[n + 1], dp[n + 1];
    for (i = 0; i <= n; i++)
    {
        dp_new[i] = dp[i] = 0;
    }
    dp[0] = 1.0;

    // for (i = 0; i < n; i++)
    // {
    //     int j;
    //     for (j = 0; j <= i; j++)
    //     {
    //         dp_new[j + 1] += dp[j] * a[i];
    //         dp_new[j] += dp[j] * (1.0 - a[i]);
    //     }
    //     for (j = 0; j <= i + 1; j++)
    //     {
    //         dp[j] = p_new[j];
    //         dp_new[j] = 0;
    //     }
    // }
    for (i = 0; i < n; i++)
    {
        int j;
        for (int j = i+1; j >= 0; j--)
        {
            dp[j] = (j == 0 ? 0 : dp[j - 1] * a[i]) + dp[j] * (1 - a[i]);
            
        }
        
        

        
    }

    double ans = 0.0;

    for (i = n / 2 + 1; i <= n; i++)
        ans += dp[i];
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}