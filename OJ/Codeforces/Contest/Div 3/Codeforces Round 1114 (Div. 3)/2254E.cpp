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

    // ordered_set<pair<int,int>>os;
    // os.insert({-1,3});
    // os.insert({-1,4});
    // //os.insert({1,1});
    // int ind=os.order_of_key({1,0});
    // cout<<ind<<endl;

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        int n, m, i, j, k;
        cin >> n;
        int a[n + 1];
        ordered_set<pair<int, int>> os;
        for (i = 1; i <= n; i++)
        {
            cin >> a[i];
            os.insert({a[i], i});
        }
        vector<int> ans;
        int val = 1;
        int flag = 1;
        for (i = 0; i < n; i++)
        {
            if (i == 0)
            {
                int ind = os.order_of_key({val, 0});
                if (os.size() <= ind)
                {
                    flag = 0;
                    break;
                }
                auto it = os.find_by_order(ind);
                ans.push_back(it->first);
                val = it->first;
                os.erase(it);
            }
            else
            {
                int ind = os.order_of_key({-val+1, 0});
                if (os.size() <= ind)
                {
                    flag = 0;
                    break;
                }
                auto it = os.find_by_order(ind);
                ans.push_back(val+it->first);
                val += it->first;
                os.erase(it);
            }
        }
        if(flag)
        {
            for(auto it:ans)cout<<it<<" ";
            cout<<endl;
        }
        else cout<<-1<<endl;
    }

    return 0;
}