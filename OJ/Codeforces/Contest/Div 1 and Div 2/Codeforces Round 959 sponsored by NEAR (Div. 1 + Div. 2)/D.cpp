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
        int marked[n + 1] = {};
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<pair<int, int>> ans;

        int x = n - 1;
        int flag = 0;
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (a[i] % x == a[j] % x)
                {
                    ans.push_back({i, j});
                    marked[i] = marked[j] = 1;
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
        while (--x > 0)
        {
           
            int ind = ans.back().first;
            int val = a[ind];
            for (i = 0; i < n; i++)
            {
                if (val % x == a[i] % x && marked[i] == 0)
                {
                    marked[i] = 1;
                    ans.push_back({ind, i});
                    break;
                }
            }
        }
        rev(ans);
        cout << "YES\n";
        for (auto it : ans)
            cout << it.first + 1 << " " << it.second + 1 << endl;
    }

    return 0;
}