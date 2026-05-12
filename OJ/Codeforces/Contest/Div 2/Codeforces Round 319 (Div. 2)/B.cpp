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

    int n, m;
    cin >> n >> m;
    int a[n];
    int i, j;
    inputa(a, n, 0);
    if (n > m)
        cout << "YES\n";
    else
    {
        int flag = 0;

        int dp[n+1][m] = {};

        for (i = 0; i < n; i++)
        {
            dp[i+1][a[i]%m]=1;
            for (j = 0; j < m; j++)
            {
                //cout << dp[i][j] << " ";
                if (dp[i][j])
                {
                    dp[i + 1][(j + a[i]) % m] = 1;
                    dp[i + 1][j] = dp[i][j];
                }
                
            }
            
            
            // cout<<i<<" "<<dp[i][0]<<endl;
        }
       
        if (dp[n][0])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}