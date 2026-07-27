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
int bin_exp(int a, int b, int mod)
{
    if (b == 0) return 1;

    int val = bin_exp(a, b / 2, mod);

    if (b % 2 == 0) return (1LL * val * val) % mod;
    else return (1LL * val * val % mod * a) % mod;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    if (sum % 2 == 1)
        cout << 0 << endl;
    else
    {
        sum /= 2;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = 1;
            for (int j = 1; j <= sum; j++)
            {
                if (i <= j)
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - i]) % M;
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        int p=dp[n][sum];
        int q=bin_exp(2,M-2,M);
        int ans=(p*q)%M;
        cout<<ans<<endl;
    }
    

    return 0;
}