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
        int b[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(a, a + n);
        if (a[0] > 0)
            cout << -1 << endl;
        else
        {
            map<int, int> mp;
            int sum = 0;
            map<int, int> cnt;
            for (i = 0; i < n; i++)
                cnt[a[i]]++;
            int last_used = 0;
            int last_val=0;
            int flag = 1;

            for (auto it : cnt)
            {

                if (it.first == 0)
                    continue;
                    // cout<<"okay\n";

                if (it.first < sum + (last_used)*cnt[last_val])
                {
                    flag = 0;
                
                    break;
                }
                // cout<<"done\n";
                // cout << cnt[last_val] << endl;
                int val = (it.first - sum) / cnt[last_val];
                
                // cout<<val<<endl;
                if ((it.first - sum) % cnt[last_val] != 0 || val <= last_used)
                {
                    flag = 0;
                    break;
                }
                mp[last_val] = val;
                sum += val * cnt[last_val];
                last_used = val;
                last_val=it.first;
            }
            mp[a[n - 1]] = last_used + 1;
            if (flag)
            {
                for (i = 0; i < n; i++)
                    cout << mp[b[i]] << " ";
                cout << endl;
            }
            else
                cout << -1 << endl;
        }
    }

    return 0;
}