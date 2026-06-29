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
        cin >> n >> k;
        int a[n + 1];
        int b[n];
        int c[n], d[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            c[i]=a[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> b[i];
            d[i]=b[i];
        }
        sort(c,c+n);
        sort(d,d+n);
        int f1=1,f2=1,ans1=0,ans2=0;
        for(i=0;i<n;i++)
        {
            if(a[i]<b[i])f1=0;
            else ans1+=a[i]-b[i];
            if(c[i]<d[i])f2=0;
            else ans2+=c[i]-d[i];
        }
        ans2+=k;
        if(f2==0)cout<<-1<<endl;
        else if(f1)cout<<min(ans1,ans2)<<endl;
        else cout<<ans2<<endl;
    }

    return 0;
}