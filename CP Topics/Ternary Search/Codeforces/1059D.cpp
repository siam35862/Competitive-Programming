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

double eulen(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int f(int *x, int *y, int n, double cy)
{
    double cxl = -1e7, cxr = 1e7;

    int i;

    for (i = 0; i < n; i++)
    {
        if (1.0 * y[i] > 2 * cy)
        {

            return 0;
        }
        double dx = sqrt(2*cy * y[i] - y[i] * y[i]);
        cxl = max(cxl, x[i] - dx);
        cxr = min(cxr, dx + x[i]);
    }
    if (cxl < cxr)
        return 1;
    else
        return 0;
}

double ternary_search_minimum_doubles(int *x, int *y, int n, double l, double r)
{
    for (int i = 0; i < 100; i++)
    {
        double m1 = l + (r - l) / 3.0;
        double m2 = r - (r - l) / 3.0;
        int v1 = f(x, y, n, m1);
        int v2 = f(x, y, n, m2);
        if (v1 == v2 && v1 == 1)
            r = m1;
        else if (v1 == 0 && v2 == 1)
        {
            l = m1;
            r = m2;
        }
        else if (v1 == 0 && v2 == 0)
        {
            l = m2;
        }
    }
    return (l + r) / 2.0;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int x[n], y[n], i;
    int positive = 0, negative = 0;
    int mx = INT64_MIN, mn = INT64_MAX;
    for (i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        if (y[i] > 0)
            positive++;
        else
            negative++;
        mx = max(mx, x[i]);
        mn = min(mn, x[i]);
        y[i] = abs(y[i]);
    }

    if (negative && positive)
        cout << -1 << endl;
    else
    {
        double ans = ternary_search_minimum_doubles(x, y, n, 0, double(1e14));
        cout << fixed << setprecision(10) << ans << endl;
    }

    return 0;
}