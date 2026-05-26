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

#define maxn (int)(3e3 + 5)
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
pair<int, int> dp[maxn][maxn][2];

pair<int, int> optimalvalue(int *a, int i, int j, int turn)
{
    if (i > j)
        return {0, 0};
    if (dp[i][j][turn].first > 0 && dp[i][j][turn].second > 0)
        return dp[i][j][turn];
    auto p1 = optimalvalue(a, i + 1, j, (turn + 1) % 2);
    auto p2 = optimalvalue(a, i, j - 1, (turn + 1) % 2);
    if (turn == 0)
    {
        if (p1.first + a[i] > p2.first + a[j])
        {
             dp[i][j][turn] = {p1.first + a[i], p1.second};
        }
        else
             dp[i][j][turn] = {p2.first + a[j], p2.second};
    }
    else
    {
        if (p1.second + a[i] > p2.second + a[j])
        {
             dp[i][j][turn] = {p1.first, p1.second+a[i]};
        }
        else
             dp[i][j][turn] = {p2.first, p2.second+a[j]};
    }
    
   
    return dp[i][j][turn];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, i;
    cin >> n ;
    int a[n];
    inputa(a, n, 0);

    auto p = optimalvalue(a, 0, n - 1, 0);
  
    cout << p.first - p.second << endl;

    return 0;
}