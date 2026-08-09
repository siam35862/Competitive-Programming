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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        int n, m, i, j, k;

        cin >> n;
        string s;
        cin >> s;

        int ans = 0;

        int flag = 1, v;

        flag = 0;
        i = 0;
        v = 0;
        if ((s[i] == '0' || s[i] == '?') && (s[i + 1] == '0' || s[i+1] == '?'))
        {
            flag = 1;
            for (i = 0; i < n; i += 2)
            {
                if ((s[i] != v + 48 && s[i] != '?') || (i + 1 < n && s[i + 1] != v + 48 && s[i + 1] != '?'))
                {
                    flag = 0;
                    break;
                }
                v ^= 1;
            }
        }
  
        if (flag)
            ans++;
        flag = 0;
        i = 0;
        v = 1;
        if ((s[i] == '1' || s[i] == '?') && (s[i + 1] == '1' || s[i+1] == '?'))
        {
            flag = 1;
            for (i = 0; i < n; i += 2)
            {
                if ((s[i] != v + 48 && s[i] != '?') || (i + 1 < n && s[i + 1] != v + 48 && s[i + 1] != '?'))
                {
                    flag = 0;
                    break;
                }
                v ^= 1;
            }
        }
        if (flag)
            ans++;

        flag = 0;
        i = 0;
        v = 1;
        if ((s[i] == '0' || s[i] == '?') && (s[i + 1] == '1' || s[i+1] == '?'))
        {
            flag = 1;
            for (i = 1; i < n; i += 2)
            {
                if ((s[i] != v + 48 && s[i] != '?') || (i + 1 < n && s[i + 1] != v + 48 && s[i + 1] != '?'))
                {
                    flag = 0;
                    break;
                }
                v ^= 1;
            }
        }
        if (flag)
            ans++;
        flag = 0;
        i = 0;
        v = 0;
        if ((s[i] == '1' || s[i] == '?') && (s[i + 1] == '0' || s[i+1] == '?'))
        {
            flag = 1;
            for (i = 1; i < n; i += 2)
            {
                if ((s[i] != v + 48 && s[i] != '?') || (i + 1 < n && s[i + 1] != v + 48 && s[i + 1] != '?'))
                {
                    flag = 0;
                    break;
                }
                v ^= 1;
            }
        }
        if (flag)
            ans++;

        cout << ans << endl;
    }

    return 0;
}