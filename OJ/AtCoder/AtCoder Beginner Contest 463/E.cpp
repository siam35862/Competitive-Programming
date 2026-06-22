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

void shortest_path(int src, vector<vector<pair<int, int>>> &graph, int *ans)
{
    ans[src] = 0;
    int visited[graph.size()]={};
    set<pair<int,int>> st;
    st.insert({0,1});
    while (st.size())
    {
        auto it = *st.begin();
        st.erase(st.begin());
        int u = it.second,  w = it.first;
        if (visited[u]) continue;
        visited[u] = true;
       

        for(auto dest:graph[u])
        {
            if(w+dest.second<ans[dest.first])
            {
                ans[dest.first]=w+dest.second;
                st.insert({ans[dest.first],dest.first});
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, y;
    cin >> n >> m >> y;
    vector<vector<pair<int, int>>> graph(n + 3);
    int i;
    for (i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int x[n];
    graph[n + 1].push_back({n + 2, y});
    for (i = 0; i < n; i++)
    {
        cin >> x[i];
        graph[i + 1].push_back({n + 1, x[i]});
        graph[n + 2].push_back({i + 1, x[i]});
    }
    int ans[n + 3];
    for (i = 0; i <= n + 2; i++)
        ans[i] = inf;
    shortest_path(1, graph, ans);
    for (i = 2; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}