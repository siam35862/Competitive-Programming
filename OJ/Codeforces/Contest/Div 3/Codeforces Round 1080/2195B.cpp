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
#define maxsize 100000005
#define max_n 262144 + 100

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
    tree<T, null_type, comparator<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_setd = tree<T, null_type, greater<T>, rb_tree_tag,
                          tree_order_statistics_node_update>;
int bin_exp(int a, int b)
{
    if (b == 0)
        return 1;
    int v = bin_exp(a, b / 2);
    if (b % 2 == 0)
        return (v * v) % M;
    else
        return (((v * v) % M) * a) % M;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1], b[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b + 1, b + n + 1);
        int fl = 1;
        int visited[n + 1] = {};
        vector<vector<int>> v(n / 2 + 1);
        for (int i = 1; i <= n / 2; i++)
        {
            if (!visited[i])
            {
                int u = i;
                while (u <= n)
                {
                    visited[u] = 1;
                    v[i].push_back(a[u]);
                    u *= 2;
                }
            }
        }
        for (auto &it : v)
            srt(it);
        int visited1[n + 1] = {};
        for (int i = 1; i <= n / 2; i++)
        {
            if (!visited1[i])
            {
                int u = i;
                for(auto it:v[i])
                {
                    a[u]=it;
                    u*=2;
                }
            }
        }
        int i;
        for(i=1;i<=n;i++)if(a[i]!=b[i])fl=0;
        if (fl)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}