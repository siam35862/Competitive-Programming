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

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        int n, m, i, j, k;
        int x, y;
        cin >> x >> y;
        int target = x + y;
        int yy = y;
        int bit = 0;
        int temp = target;
        while (temp > 0)
        {
            bit++;
            temp /= 2;
        }
        int c = 0;
        for (i = 0; i < bit; i++)
        {
            int cnt = 0;
            if ((c & (1 << i)))
                cnt++;
            if ((x & (1 << i)))
                cnt++;
            if ((y & (1 << i)))
                cnt++;
            if (cnt == 3)
            {
                c ^= (1 << i);
                y ^= (1 << i);
                c |= (1 << (i + 1));
            }
            else if (cnt == 2)
            {
                c |= (1 << (i + 1));
                if ((x & (1 << i)))
                {
                    for (int j = i - 1; j >= 0; j--)
                    {
                        if ((y & (1 << j)))
                        {
                            y &= (~(1 << j));
                            x |= (1 << j);
                        }
                    }
                }
                c &= (~(1 << i));
                x &= (~(1 << i));
                y &= (~(1 << i));
            }
            else if (cnt == 1)
            {
                if ((c & (1 << i)))
                {
                    c &= (!(1 << i));
                    y ^= (1 << i);
                }
            }

            // cout << x << " " << y << " " << c << endl;
        }
        // cout << c << endl;
        if ((c & (1 << i)))
        {
            c &= (!(1 << i));
            y ^= (1 << i);
        }
        // cout << x << " " << y << endl;
        cout << target << " " << y - yy << endl;
    }

    return 0;
}