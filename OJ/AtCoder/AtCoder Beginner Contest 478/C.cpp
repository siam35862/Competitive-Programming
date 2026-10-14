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

    int n, k;
    cin >> n >> k;
    int a[n];
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int b[n] = {};
    int c[n] = {};
    c[n - 1] = 1;
    b[0] = 1;
    for (i = 1; i < n; i++)
    {
        if (a[i] >= a[i - 1])
        {
            b[i] = 1;
        }
        else
            break;
        // cout << i << endl;
    }
    for (i = n - 2; i >= 0; i--)
    {
        if (a[i] <= a[i + 1])
        {
            c[i] = 1;
        }
        else
            break;
        // cout << i << endl;
    }
    vector<pair<int, int>> s(n + k +1);
    map<int, int> mp;
    int r = 0;
    for (int l = 0; l < n - k + 1; l++)
    {
        while (r < l + k)
        {
            mp[a[r]]++;
            r++;
        }
        s[l].first = mp.begin()->first;
        auto it = mp.end();
        it--;
        s[l].second = it->first;
        mp[a[l]]--;
        if (mp[a[l]] == 0)
            mp.erase(a[l]);
        // cout << l << " " << s[l].first << " " << s[l].second << endl;
    }
    int flag = 0;
    for (i = 0; i < n - k + 1; i++)
    {
        if (i == 0)
        {
            if (i + k == n)
            {
                flag = 1;
                break;
            }
            else
            {
                if (c[i + k] == 1 && s[i].second <= a[i + k])
                {
                    flag = 1;
                    break;
                }
            }
        }
        else
        {
            if (i + k == n)
            {
                if (b[i - 1] == 1 && a[i - 1] <= s[i].first)
                {
                    flag = 1;
                    break;
                }
            }
            else
            {
                if (b[i - 1] == 1 && a[i - 1] <= s[i].first && c[i + k] == 1 && s[i].second <= a[i + k])
                {
                    flag = 1;
                    break;
                }
            }
        }
    }
    if (flag)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}