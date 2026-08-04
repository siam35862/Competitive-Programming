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

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int ans = 1;
        int flag = 0;
        int x;
        map<int, int> mp;
        int cnt = 0;
        for (i = 0; i < n / 2; i++)
        {
            if (a[i] == a[n - i - 1])
                continue;
            else if (abs(a[i] - a[n - i - 1]) == 2)
            {
                
                x = (a[i] + a[n - i - 1]) / 2;
                cnt++;
                mp[x]++;
                mp[x-1]++;
            }
            else
            {

                ans = 0;
                break;
            }
        }
        for(auto it:mp)
        {
            if(it.second==cnt)
            {
                flag=1;
                break;
            }
        }
        if(cnt==0)flag=1;
        if (ans&&flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}