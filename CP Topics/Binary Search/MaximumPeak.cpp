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
/*
T test cases:
In each test case, you have an array which strictly increases first, then strictly decreases.
Now, find the maximum value in interval l to r inclusive.
2
6
10 15 20 20 6 7 
2 5
8
10 20 19 18 17 16 15 14 
2 8
*/

int f(int *a, int ind)
{
    return a[ind];
}

int binary_search_maximum(int *a, int l, int r)
{
    if (l == r)
        return l;
    else if (f(a, r) > f(a, r - 1))
        return r;
    else if (f(a, l) > f(a, l + 1))
        return l;
    while (l<r)
    {
        int m=(l+r)>>1;
        if(f(a,m)==f(a,m+1))return m;
        else if(f(a,m)<f(a,m+1))
        {
            l=m+1;
        }
        else r=m;

    }
    
    return l;
}

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
        int a[n + 1];

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int ind = binary_search_maximum(a, l, r);
        cout << a[ind] << endl;
    }

    return 0;
}