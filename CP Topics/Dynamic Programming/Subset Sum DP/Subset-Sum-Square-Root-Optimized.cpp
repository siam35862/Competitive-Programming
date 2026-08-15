// You are given an array of N integers. Print the possible subset sum 1 to S where total sum is bounded by S. (1<=N<=10^5)
// time complexity O(S√S)
// Here, the sum is Bounded by N
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
#define M998 998244353
#define M7 1000000007
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

    int n, i;

    cin >> n;
    int a[n + 1];

    map<int, int> mp;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<vector<int>> dp(2, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    int dp_ind = 0;
    for (auto &[v, k] : mp)
    {

        dp[(dp_ind ^ 1)] = dp[dp_ind];

        for (int j = 0; j < v; j++)
        {
            int sum = 0;
            for (int multiple = j, count = 0; multiple <= n; multiple += v, count++)
            {
                if (count > k)
                {
                    count--;
                    sum -= dp[dp_ind][multiple - k * v];
                }
                if (sum > 0)
                    dp[(dp_ind ^ 1)][multiple] = 1;
                sum += dp[dp_ind][multiple];
            }
        }
        dp_ind ^= 1;
    }

    for (i = 0; i <= n; i++)
    {
        if (dp[dp_ind][i])
            cout << i << " ";
    }
    cout << endl;

    return 0;
}