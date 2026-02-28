#include <bits/stdc++.h>

using namespace std;

#define int long long

void dfs(int u, int *visited, vector<int> &outtime, vector<vector<int>> &graph)
{
    if (visited[u])
        return;
    visited[u] = 1;

    for (auto v : graph[u])
        dfs(v, visited, outtime, graph);
    outtime.push_back(u);
}

void dfs(int u, int cn, int *visited, int *component_no, vector<vector<int>> &components, vector<vector<int>> &graph)
{
    if (visited[u])
        return;
    visited[u] = 1;
    component_no[u] = cn;
    components[cn].push_back(u);

    for (auto v : graph[u])
        dfs(v, cn, visited, component_no, components, graph);
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    vector<vector<int>> graph1(n + 1), graph2(n + 1);
    int i;
    int ss, ee;
    cin >> ss >> ee;

    int a[n + 1];
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 0; i < m; i++)
    {
        cin >> edges[i].first >> edges[i].second;

        graph1[edges[i].first].push_back(edges[i].second);
        graph2[edges[i].second].push_back(edges[i].first);
    }

    vector<int> outtime;
    int visited[n + 1] = {};
    for (i = 1; i <= n; i++)
        dfs(i, visited, outtime, graph1);
    reverse(outtime.begin(), outtime.end());
    int component_no[n + 1] = {};
    vector<vector<int>> components(n + 1);
    int cn = 0;
    int visited2[n + 1] = {};

    for (auto u : outtime)
        if (!visited2[u])
        {
            cn++;
            dfs(u, cn, visited2, component_no, components, graph2);
        }
    int val[cn + 1] = {};
    for (i = 1; i <= n; i++)
        val[component_no[i]] += a[i];
    vector<vector<int>> agraph(cn + 1);
    for (auto e : edges)
    {
        int u = e.first, v = e.second;
        if (component_no[u] != component_no[v])
            agraph[component_no[u]].push_back(component_no[v]);
    }

    int visited3[cn + 1] = {};
    int dp[cn + 1] = {};
    dp[component_no[ss]] = val[component_no[ss]];
    vector<int> toposort;
    dfs(component_no[ss], visited3, toposort, agraph);

    reverse(toposort.begin(), toposort.end());

    for(auto u:toposort)
    {
        for(auto v:agraph[u])
        {
            dp[v]=max(dp[v],dp[u]+val[v]);
        }
    }
    cout<<dp[component_no[ee]]<<endl;

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