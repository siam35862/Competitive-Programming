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

vector<vector<int>> divisors(maxn + 1);

void sieve()
{
    int i, j;
    for (i = 1; i <= maxn; i++)
    {
        for (j = i; j <= maxn; j += i)
        {
            divisors[j].push_back(i);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve();

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        int n, m, i, j, k;
        int target_sum;
        cin >> n >> target_sum;
        int a[n + 1];
        int freq[n + 1] = {};
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]]++;
        }
        bool flag = 0;
        int aa = 0, x = 0, b = 0, y = 0;
        for (i = 1; i <= n; i++)
        {
            if (flag)
                break;

            for (j = 1; j <= freq[i]; j++)
            {
                if (flag)
                    break;
                int p = j * i;
                int q = target_sum - p;
                if (q > 0)
                {
                    for (auto it : divisors[q])
                    {
                        int count = q / it;
                        if (it <= n && freq[it] >= count)
                        {
                            if (it != i || (it == i && freq[it] >= j + count))
                            {
                                flag = 1;
                                aa = j;
                                x = i;
                                b = count;
                                y = it;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (flag&&aa>0&&b>0)
            cout << aa << " " << x << " " << b << " " << y << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}