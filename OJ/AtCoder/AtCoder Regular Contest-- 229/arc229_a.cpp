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

    int n;
     cin >> n;
    if (n == 0)
    {
        cout << "SIAM\n";
    }
    else
    {
        string s = "ARC";
        int v = 1;
        map<int, string> mp;
        mp[v] = s;
        string pre;
        for (int i = 1; i <= 25; i++)
        {
            string suff = "ARC";
            for (int j = 2; j <= 25; j++)
            {

                suff += "RC";
                if (mp.find(i * j) == mp.end())
                    mp[i * j] = pre + suff;
                else if (mp[i * j].size() > pre.size() + suff.size())
                {
                    mp[i * j] = pre + suff;
                }
            }
            pre += "AR";
        }

        // for (auto it : mp)
        // {
        //     cout << it.first << " " << it.second.size() << endl;
        // }
        map<int, pair<int, vector<int>>> mp_ans;
        for (int i = 1; i <= 600; i++)
        {
            if (mp.find(i) != mp.end())
            {
                mp_ans[i] = {(int)mp[i].size(), {i}};
            }
            else
            {
                int j = 1;
                int k = i - j;

                vector<int> v1 = mp_ans[j].second;
                vector<int> v2 = mp_ans[k].second;
                v1.insert(v1.end(), v2.begin(), v2.end());
                mp_ans[i] = {mp_ans[j].first + mp_ans[k].first, v1};
            }
            for (int j = 1; j < i; j++)
            {
                int k = i - j;
                if (mp_ans[i].first > mp_ans[j].first + mp_ans[k].first)
                {
                    vector<int> v1 = mp_ans[j].second;
                    vector<int> v2 = mp_ans[k].second;
                    v1.insert(v1.end(), v2.begin(), v2.end());
                    mp_ans[i] = {mp_ans[j].first + mp_ans[k].first, v1};
                }
            }
           // cout << i << " " << mp_ans[i].first << endl;
        }
        string ans;
        for (auto it : mp_ans[n].second)
            // cout << ans << endl;
            ans += mp[it];
        cout << ans << endl;
        //cout << ans.size() << endl;
    }
    return 0;
}