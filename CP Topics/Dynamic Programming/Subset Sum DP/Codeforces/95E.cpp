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

void dfs(int u, int *visited, vector<vector<int>> &graph, int &numofnode)
{
    if (visited[u])
        return;
    visited[u] = 1;
    numofnode++;
    for (auto v : graph[u])
    {
        dfs(v, visited, graph, numofnode);
    }
}
bool isluckynumber(int n)
{
    bool flag = 1;
    while (n > 0)
    {
        if (n % 10 != 4 && n % 10 != 7)
        {
            flag = 0;
            break;
        }
        n /= 10;
    }
    return flag;
}
int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    int i;
    for (i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> v;
    int visited[n + 1] = {};
    for (i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            int numofnode = 0;
            dfs(i, visited, graph, numofnode);
            v.push_back(numofnode);
        }
    }
    map<int, int> mp;
    for (auto it : v)
    {
        
        mp[it]++;
    }
   

    vector<int> dp(n + 1, inf);
    dp[0] = 0;

    for (auto &[w, k] : mp)
    {
        vector<int> ndp;
        ndp = dp;

        for (int i = 0; i < w; i++)
        {
            deque<pair<int, int>> dq;
            for (int j = i, count = 0; j <= n; j += w, count++)
            {
                while (!dq.empty() && dq.front().second < count - k)
                    dq.pop_front();
                if (!dq.empty())
                    ndp[j] = min(ndp[j], dq.front().first + count);
                while (!dq.empty() && dq.back().first >= dp[j] - count)
                    dq.pop_back();
                dq.push_back({dp[j] - count, count});
            }
        }
        swap(dp, ndp);
    }
    
    int ans = inf;
    for (i = 1; i <= n; i++)
    {
        if (dp[i] != inf)
        {
            if (isluckynumber(i))
                ans = min(ans, dp[i]);
        }
    }
    if (ans == inf)
        cout << -1 << endl;
    else
        cout << ans-1 << endl;

    return 0;
}