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

    int n, k, x, a, b, c;
    cin >> n >> k;
    cin >> x >> a >> b >> c;
    int ans = 0;
    int arr[n + 1];
    arr[0] = x;
    int orl[n + 1], orr[n + 1];
    for (int i = 1; i < n; i++)
    {
        arr[i] = (a * arr[i - 1] + b) % c;
    }

    for (int i = 0; i < n; i += k)
    {
        int j;
        for (j = i; j < n && j < i + k; j++)
        {
            if (j == i)
                orl[j] = arr[j];
            else
                orl[j] = (orl[j - 1] | arr[j]);
        }
        for (j = min(n - 1, i + k - 1) - 1, orr[j + 1] = arr[j + 1]; j >= i; j--)
        {
            orr[j] = (orr[j + 1] | arr[j]);
        }
    }
    for (int i = k - 1; i < n; i++)
        ans ^= (orl[i] | orr[i - k + 1]);
    cout << ans << endl;

    return 0;
}