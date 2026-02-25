#include <bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int u, int &timer, int &cn, stack<int> &st, vector<int> &intime, vector<int> &mintime, vector<int> &roots,
         vector<vector<int>> &graph, vector<vector<int>> &components)
{
    intime[u] = mintime[u] = ++timer;
    st.push(u);

    for (auto v : graph[u])
    {

        if (intime[v] == -1)
            dfs(v, timer, cn, st, intime, mintime, roots, graph, components);
        if (roots[v] == -1)
            mintime[u] = min(mintime[u], mintime[v]);
    }

    if (mintime[u] == intime[u])
    {
        components.push_back({u});
        cn++;
        while (!st.empty())
        {
            auto v = st.top();
            st.pop();
            roots[v] = cn;
            if (u == v)
                break;
            components.back().push_back(v);
        }
    }
}
int ans = 0;
void dfs(int u,int p, int carry, int *val, int *visited, int *dp, vector<vector<int>> &graph)
{
    if (visited[u])
        return;

    visited[u] = 1;
    for (auto v : graph[u])
    {
        if(v!=p)
        dp[v] = max(dp[v], dp[u] + val[v]);
        dfs(v,u, carry, val, visited, dp, graph);
    }
}
void dfs1(int u, int *visited, vector<int> &toposort, vector<vector<int>> &graph)
{
    if (visited[u])
        return;
    visited[u] = 1;
    for (auto v : graph[u])
    {

        dfs1(v, visited, toposort, graph);
    }
    toposort.push_back(u);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int s, e;
    cin >> s >> e;
    int i, j;
    vector<vector<int>> graph(n + 1), components;
    vector<pair<int, int>> edges(m + 1);
    int a[n + 1];
    for (i = 1; i <= n; i++)
        cin >> a[i];

    for (i = 0; i < m; i++)
    {
        cin >> edges[i].first >> edges[i].second;

        graph[edges[i].first].push_back(edges[i].second);
    }
    stack<int> st;
    vector<int> intime(n + 1, -1), mintime(n + 1, -1), roots(n + 1, -1);
    int timer = 0, cn = 0;
    for (i = 1; i <= n; i++)
    {
        if (intime[i] == -1)
            dfs(i, timer, cn, st, intime, mintime, roots, graph, components);
    }
    vector<vector<int>> agraph(cn + 1);
    int val[cn + 1] = {};
    for (i = 1; i <= n; i++)
        val[roots[i]] += a[i];
    for (auto edge : edges)
    {
        int u = edge.first, v = edge.second;
        if (roots[u] != roots[v])
            agraph[roots[u]].push_back(roots[v]);
    }

   

    int visited3[cn + 1] = {};
    int dp[cn + 1] = {};
    dp[roots[s]] = val[roots[s]];
    vector<int> toposort;
    dfs1(roots[s], visited3, toposort, agraph);

    reverse(toposort.begin(), toposort.end());

    for(auto u:toposort)
    {
        for(auto v:agraph[u])
        {
            dp[v]=max(dp[v],dp[u]+val[v]);
        }
    }
    cout<<dp[roots[e]]<<endl;
}

/*

7 8
1 2
2 3
3 1
3 4
4 5
5 6
6 7
7 5

*/