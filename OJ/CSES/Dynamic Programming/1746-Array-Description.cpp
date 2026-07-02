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
#define M (int)1e9+7
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

    int n, m;
    cin >> n >> m;
    int a[n];
    inputa(a, n, 0);

    int dp[n][m + 1] = {};
    int i;
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (a[i] == 0)
            {
                for (int j = 1; j <= m; j++)
                {
                    dp[i][j] = 1;
                }
            }
            else
                dp[i][a[i]] = 1;
        }
        else
        {
            if (a[i] != 0)
            {
                for (int j = a[i] - 1; j <= a[i] + 1; j++)
                {
                    if (j <= m && j >= 1)
                    {
                        dp[i][a[i]] += dp[i-1][j];
                        dp[i][a[i]]%=M;
                    }
                }
            }
            else
            {
                for (int j = 1; j <= m; j++)
                {
                    for (int k = j - 1; k <= j + 1; k++)
                    {
                        if (k >= 1 && k <= m)
                        {
                            dp[i][j] += dp[i-1][k];
                            dp[i][j]%=M;
                        }
                    }
                }
            }
        }
    }
    int ans=0;
    if(a[n-1]==0)
    {
        for(i=1;i<=m;i++)
        {
            ans+=dp[n-1][i];
        }
    }
    else ans=dp[n-1][a[n-1]];
    cout<<ans<<endl;
    return 0;
}