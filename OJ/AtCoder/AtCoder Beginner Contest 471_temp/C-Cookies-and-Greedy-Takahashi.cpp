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

    int n, i;
    cin >> n;
    int a[n + 1];
    ordered_set<int> os1;
    ordered_setd<int> os2;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        os1.insert(a[i]);
        os2.insert(a[i]);
    }
    int pos = 0;
    int ans = 0;
    while (!os1.empty())
    {
        int ind1 = os1.order_of_key(pos);
        int ind2 = os2.order_of_key(pos);
       // cout<<ind1<<" "<<ind2<<endl;

        if (ind1 == 0)
        {
            int val = abs(pos - *os2.find_by_order(ind2 - 1));
            ans += val;
            pos = *os2.find_by_order(ind2 - 1);
            os1.erase(pos);
            os2.erase(pos);
        }
        else if (ind2 == 0)
        {
            int val = abs(pos - *os1.find_by_order(ind1 - 1));
            ans += val;
            pos = *os1.find_by_order(ind1 - 1);
            os1.erase(pos);
            os2.erase(pos);
        }
        else
        {
            int val1 = abs(pos - *os1.find_by_order(ind1 - 1));
            int val2 = abs(pos - *os2.find_by_order(ind2 - 1));
            //cout<<" v "<<val1<<" "<<val2<<endl;
            if (val1 <= val2)
            {
                ans += val1;
                pos = *os1.find_by_order(ind1 - 1);
                os1.erase(pos);
                os2.erase(pos);
            }
            else
            {
                ans += val2;
                pos = *os2.find_by_order(ind2 - 1);
                os1.erase(pos);
                os2.erase(pos);
            }
        }
        //cout<<pos<<endl;
    }
    cout<<ans<<endl;

    return 0;
}