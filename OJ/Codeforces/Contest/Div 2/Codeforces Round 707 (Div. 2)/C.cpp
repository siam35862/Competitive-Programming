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

    int n, i;
    cin >> n;
    int a[n + 1];

    vector<pair<int, int>> v;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        v.push_back({a[i], i + 1});
    }
    srt(v);
    int j;
    map<int, pair<int, int>> mp;
    int x,y,z,w;
    int flag=0;
    int m=min(n,1573LL);
    for (i = 0; i < m; i++)
    {
        for (j = i + 1; j < m; j++)
        {
            int diff=v[j].first - v[i].first;
            if (mp.find(diff) == mp.end())
                mp[diff] = {v[i].second, v[j].second};
            else
            {
                x=mp[diff].first;
                y=mp[diff].second;
                z=v[i].second;
                w=v[j].second;
                if(x==z||x==w||y==z||y==w)continue;
                else
                {
                    flag=1;
                    break;
                }

            }
        }
        if(flag)break;
    }
    if(flag)cout<<"YES\n"<<x<<" "<<w<<" "<<y<<" "<<z<<endl;
    else cout<<"NO\n";

    return 0;
}