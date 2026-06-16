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

#define maxn (int)(1001)
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

int dp[maxn][maxn][2];

void dp_value(int *a, int *b, int i, int j, int turn)
{
    if (i <= 0 && j <= 0)
    {

        dp[i][j][0] = dp[i][j][1] = 0;
        return;
    }
    if (dp[i][j][turn] != -1)
    {
        return;
    }

    if (i == 0)
    {
        dp_value(a, b, i, j - 1, (turn + 1) % 2);

        if (turn == 0)
        {
            dp[i][j][0] = dp[i][j - 1][0] + b[j];
            dp[i][j][1] = dp[i][j - 1][1];
        }
        else
        {
            dp[i][j][1] = dp[i][j - 1][1] + b[j];
            dp[i][j][0] = dp[i][j - 1][0];
        }
    }
    else if (j == 0)
    {
        dp_value(a, b, i - 1, j, (turn + 1) % 2);

        if (turn == 0)
        {
            dp[i][j][0] = dp[i - 1][j][0] + a[i];
            dp[i][j][1] = dp[i - 1][j][1];
        }
        else
        {
            dp[i][j][1] = dp[i - 1][j][1] + a[i];
            dp[i][j][0] = dp[i - 1][j][0];
        }
    }
    else
    {

        if (turn == 0)
        {
            dp_value(a, b, i, j - 1, (turn + 1) % 2);
            int temp0 = dp[i][j-1][0] + b[j];
            int temp1=dp[i][j-1][1];
            dp_value(a, b, i - 1, j, (turn + 1) % 2);
            

            if (dp[i-1][j][0]+a[i] < temp0)
            {
                dp[i][j][0] = temp0;
                dp[i][j][1]=temp1;
            }
            else
            {
                dp[i][j][0]=dp[i-1][j][0]+a[i];
                dp[i][j][1]=dp[i-1][j][1];
            }
            
        }
        else
        {

            dp_value(a, b, i, j - 1, (turn + 1) % 2);
            int temp1 = dp[i][j-1][1] + b[j];
            int temp0=dp[i][j-1][0];
            dp_value(a, b, i - 1, j, (turn + 1) % 2);
            

            if (dp[i-1][j][1]+a[i] < temp1)
            {
                dp[i][j][0] = temp0;
                dp[i][j][1]=temp1;
            }
            else
            {
                dp[i][j][1]=dp[i-1][j][1]+a[i];
                dp[i][j][0]=dp[i-1][j][0];
            }
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int i;
    int a[n + 1], b[m + 1];
    inputa(a, n, 1);
    inputa(b, m, 1);
    reverse(a+1,a+n+1);
    reverse(b+1,b+n+1);
    for (i = 0; i < maxn; i++)
    {
        for (int j = 0; j < maxn; j++)
        {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }

    dp_value(a, b, n, m, 0);
    int ans=dp[n][m][0];
     
    cout<<ans<<endl;
   

    return 0;
}