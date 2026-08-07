//TLE Yet

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
        int a[n + 1];
        set<pair<int, int>> st;

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (i = 1; i < n - 1; i++)
        {
            if (abs(a[i - 1]) % 2 == abs(a[i + 1]) % 2)
            {
                if (a[i - 1] + a[i + 1] - a[i] < a[i])
                {
                    st.insert({a[i - 1] + a[i + 1] - a[i], i});
                }
            }
        }
        while (!st.empty())
        {
            auto it = *st.begin();
            st.erase(it);
            i = it.second;
            int val = it.first;
            if (i > 1)
            {
                st.erase({a[i - 2] + a[i] - a[i - 1], i - 1});
                if (a[i - 2] + val - a[i - 1] < a[i - 1] && abs(a[i - 2]) % 2 == abs(val) % 2)
                {
                    st.insert({a[i - 2] + val - a[i - 1], i - 1});
                }
            }
            if (i < n - 2)
            {
                st.erase({a[i + 2] + a[i] - a[i + 1], i + 1});
                if (a[i + 2] + val - a[i + 1] < a[i + 1] && abs(a[i + 2]) % 2 == abs(val) % 2)
                {
                    st.insert({a[i + 2] + val - a[i + 1], i + 1});
                }
            }
            a[i] = val;
        }
        outputa(a, n, 0);
        cout << endl;
    }

    return 0;
}