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

int f(int *a, int n, int p, int q, int r, int h)
{
    int val = 0, add = 0, rem = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] > h)
        {
            rem += (a[i] - h);
        }
        else
        {
            add += h - a[i];
        }
    }
    if (p + q <= r)
    {
        val = p * add + q * rem;
    }
    else
    {
        if (add > rem)
        {
            val += rem * r + (add - rem) * p;
        }
        else
            val += add * r + (rem - add) * q;
    }
    return val;
}

int ternary_search_minimum(int *a, int n, int p, int q, int rr, int l, int r)
{
    while (l < r)
    {
        int m1 = (l + r) / 2;
        int m2 = m1 + 1;
        if (f(a, n, p, q, rr, m1) > f(a, n, p, q, rr, m2))
            l = m2;
        else
            r = m1;
    }
    return l;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, p, q, r;
    cin >> n >> p >> q >> r;
    int a[n];
    int i;
    inputa(a, n, 0);
    int l = a[0], rr = a[0];
    for (i = 0; i < n; i++)
    {
        l = min(l, a[i]);
        rr = max(rr, a[i]);
    }

    int x = ternary_search_minimum(a, n, p, q, r, l, rr);
    int ans = f(a, n, p, q, r, x);
    cout << ans << endl;

    return 0;
}