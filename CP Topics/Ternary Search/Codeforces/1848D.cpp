#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int  long long
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
int f(int s, int k, int x)
{
   

       return (s+20*x)*(k-4*x);
    
}

int ternary_search_maximum(int s, int k, int l, int r)
{

    while ((r - l) > 3)
    {
        int m1 = l + (r - l) / 3;
        
        int m2 = r - (r - l) / 3;
        
        if (f(s, k, m1) < f(s, k, m2))
        {
            l = m1;
        }
        else
            r = m2;
    }
    int max_ind = l;
    for (int i = l + 1; i <= r; i++)
    {
       

            if (f(s, k, i) > f(s, k, max_ind))
            {
                max_ind = i;
            }
        
    }
    return max_ind;
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
        int s;
        cin >> s >> k;
        int ans = s * k;
        if (s % 10 == 5)
            ans = max(ans, (s + 5) * (k - 1));
        else if (s % 10)
        {
            if ((s % 10) % 2 == 1)
            {
                s += s % 10;
                k--;
            }

            for (i = 0; i < 4; i++)
            {
                int x = ternary_search_maximum(s, k, 0, k / 4);
                ans = max(ans, f(s, k, x));

                s+=s%10;
                k--;
            }
        }

        cout << ans << endl;
    }

    return 0;
}