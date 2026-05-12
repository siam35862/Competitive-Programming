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

int bin_exp(int a, int b, int mod)
{
    if (b == 0)
        return 1;

    int val = bin_exp(a, b / 2, mod);

    if (b % 2 == 0)
        return (1LL * val * val) % mod;
    else
        return (1LL * val * val % mod * a) % mod;
}

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
    int n, m, i;
    cin >> n >> m;

    int a[n + 1];

   
    inputa(a,n,0);
    if(n>m)cout<<0<<endl;
    else
    {
        int ans=1;

        for (i = 0; i < n; i++)
        {
            int j;
            for (j = i+1; j < n; j++)
            {
                ans=(ans*abs(a[i]-a[j]))%m;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}