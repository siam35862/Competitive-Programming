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

#define maxn (int)(1e6 + 100)
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

int pf[maxn + 1];
void pf_sieve()
{
    iota(pf, pf + maxn + 1, 0);
    for (int i = 2; i * i <= maxn; i++)
    {
        if (pf[i] == i)
        {
            for (int j = i * i; j <= maxn; j += i)
            {
                if (pf[j] == j)
                {
                    pf[j] = i;
                }
            }
        }
    }
}
vector<int> prime_factors(int n)
{
    vector<int> factors;
    while (n > 1)
    {
        factors.push_back(pf[n]);
        n /= pf[n];
    }
    return factors;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pf_sieve();

    int n;
    cin >> n;
    vector<int> v = prime_factors(n);
    map<int, int> mp;

    for (auto it : v)
        mp[it]++;
    int fl = 1;
    int count = mp.begin()->second;
    int val=1;
    for (auto it : mp)
    {
        if (it.second != count)
        {
            fl = 0;
        }
        count = max(count, it.second);
        val*=it.first;
    }
    //cout << count << endl;
    cout<<val<<" ";
    if (fl)
    {
        int ans = 0;
        if ((count & (count - 1)))
        {
            ans = 1;
        }
        while (count > 1)
        {
            count = (count + 1) / 2;
            ans++;
        }
        cout << ans << endl;
    }
    else
    {
        int ans = 1;
        while (count > 1)
        {
            count = (count + 1) / 2;
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}