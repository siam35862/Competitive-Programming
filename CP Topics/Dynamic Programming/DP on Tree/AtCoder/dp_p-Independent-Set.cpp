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
#define M (int)(1e9 + 7)
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

int ans = 1;
void dfs(int u, int p, vector<vector<int>> &graph, int *visited, vector<vector<int>> &dp)
{
    if (visited[u])
        return;
    visited[u] = 1;

    int v1 = 1, v2 = 1;
    for (auto v : graph[u])
    {
        dfs(v, u, graph, visited, dp);
        if (v != p)
        {
            v1 = (v1 * (dp[v][0] + dp[v][1]) % M) % M;
            v2 = (v2 * dp[v][1]) % M;
        }
    }
    
    dp[u][1] = v1;
    dp[u][0] = v2;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    int visited[n + 1] = {};
    dfs(1, 0, graph, visited, dp);
    cout << (dp[1][0] + dp[1][1]) % M << endl;

    return 0;
}