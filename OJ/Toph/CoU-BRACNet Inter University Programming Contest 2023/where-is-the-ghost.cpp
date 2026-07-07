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
    if (b == 0)
        return 1;

    int val = bin_exp(a, b / 2, mod);

    if (b % 2 == 0)
        return (1LL * val * val) % mod;
    else
        return (1LL * val * val % mod * a) % mod;
}
int dp[maxn][4][3][2][2];
int ghost_araa_count(int n, int j, int k, int l, int m, int *a)
{
    if (dp[n][j][k][l][m] != -1)
        return dp[n][j][k][l][m];
    if (n == 0)
    {
        if (j > 0 || k > 0 || l > 0 || m > 0)
        {
            return dp[n][j][k][l][m] = 0;
        }
        else
        {
            return dp[n][j][k][l][m] = bin_exp(2, n, M);
        }
    }
    else if (j == 0 && k == 0 && l == 0 && m == 0)
        return dp[n][j][k][l][m] = bin_exp(2, n, M);

    int two = 0, three = 0, five = 0, seven = 0;
    int temp = a[n - 1];
    while (temp % 2 == 0)
    {
        two++;
        temp /= 2;
    }
    while (temp % 3 == 0)
    {
        three++;
        temp /= 3;
    }
    while (temp % 5 == 0)
    {
        five++;
        temp /= 5;
    }
    while (temp % 7 == 0)
    {
        seven++;
        temp /= 7;
    }
    int val = ghost_araa_count(n - 1, j, k, l, m, a);
    val += ghost_araa_count(n - 1, max(0LL, j - two), max(0LL, k - three), max(0LL, l - five), max(0LL, m - seven), a);
    val %= M;
    return dp[n][j][k][l][m] = val;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    inputa(a, n, 0);
    int i, j, k, l, m;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j < 4; j++)
        {
            for (k = 0; k < 3; k++)
            {
                for (l = 0; l < 2; l++)
                {
                    for (m = 0; m < 2; m++)
                        dp[i][j][k][l][m] = -1;
                }
            }
        }
    }

    int ans=ghost_araa_count(n,3,2,1,1,a);
    cout<<ans<<endl;

    return 0;
}