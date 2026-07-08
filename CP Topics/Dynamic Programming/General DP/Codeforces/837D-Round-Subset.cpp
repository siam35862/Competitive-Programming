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

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    int a[n + 1];
    inputa(a, n, 1);
    int m = n * 30;
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(k + 2, vector<int>(m + 100, 0)));
    vector<vector<vector<int>>> flag(2, vector<vector<int>>(k + 2, vector<int>(m + 100, 0)));
    vector<pair<int, int>> v;
    // v.push_back({0,0});
    for (int i = 1; i <= n; i++)
    {
        int two = 0, five = 0;
        int temp = a[i];
        while (temp % 2 == 0)
        {
            two++;
            temp /= 2;
        }
        while (temp % 5 == 0)
        {
            five++;
            temp /= 5;
        }
       // cout << two << " " << five << endl;
        v.push_back({two, five});
    }
    flag[0][0][0] = 1;
    int i, j;
    for (i = 0; i < n; i++)
    {
        int ind=i&1;
      
        for (int j = 0; j <= k; j++)
        {

            for (int l = 0; l <= m; l++)
            {
              
                if ((flag[ind][j][l] == 1||l==0)&&j!=k)
                {
                    dp[(ind ^ 1)][j + 1][l + v[i].second] = max(dp[(ind^1)][j + 1][l + v[i].second], dp[ind][j][l] + v[i].first);
                    flag[(ind^1)][j+1][l+v[i].second]=1;
                    flag[(ind^1)][j][l]=1;
                    
                }
                dp[(ind^1)][j][l] = max(dp[(ind^1)][j][l], dp[ind][j][l]);
                
            }
        }
       
    }
    
    int ans = 0;

    for (i = 1; i <= m; i++)
    {
        ans = max(ans, min(i, dp[(n&1)][k][i]));
    }
    cout << ans << endl;

    return 0;
}