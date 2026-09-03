#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
//#define endl '\n'
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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt;
    for (tt = 1; tt <= 35; tt++)
    {
        string fin=to_string(tt)+".in";
        string fout=to_string(tt)+".out";
        
        freopen(fin.c_str(),"r",stdin);
        freopen(fout.c_str(),"w",stdout);
        int t = 1;
        cin >> t;
        int sum=0;
        for (int cs = 1; cs <= t; cs++)
        {
            // cout << "Case " << cs << ": ";
            int n, m, i, j, k;

            cin >> n;
            sum+=n;
            //cerr<<tt<<" "<<sum<<endl;
            int p, q;
            cin >> p >> q;
            if (q < p)
                swap(p, q);
            vector<int> a(n + 1);
            map<int, int> mp;
            priority_queue<int> pqq;
            priority_queue<int> pqp;
            for (i = 0; i < n; i++)
            {
                cin >> a[i];
                mp[a[i]]++;
            }
            for (auto it : mp)
            {
                if (it.second >= q)
                {
                    pqq.push(it.first * it.second);
                }
                else if (it.second >= p)
                {
                    pqp.push(it.first * it.second);
                }
            }

            int v1 = 0, v2 = 0, v3 = 0;
            if (!pqq.empty())
            {
                v1 = pqq.top();
                pqq.pop();
            }
            if (!pqq.empty())
            {
                v2 = pqq.top();
                pqq.pop();
            }
            if (!pqp.empty())
            {
                v3 = pqp.top();
                pqp.pop();
            }
            if (v2 > 0 && v3 > 0)
            {
                cout << max(v1 + v2, v1 + v3)<<endl;
            }
            else if (v2 > 0)
            {
                cout << v1 + v2 << endl;
            }
            else if (v1 > 0 && v3 > 0)
                cout << v1 + v3 << endl;
            else
                cout << 0 << endl;
        }
        //cerr<<tt<<endl;
    }
    return 0;
}