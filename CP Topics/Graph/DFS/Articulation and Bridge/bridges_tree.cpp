#include <bits/stdc++.h>
using namespace std;

void find_bridges(int u, int p, int &timer, int *visited, vector<vector<int>> &graph,
                  vector<int> &intime, vector<int> &mintime, vector<pair<int, int>> &edges)
{
    if (visited[u])
        return;
    visited[u] = 1;
    intime[u] = mintime[u] = timer;

    timer++;
    int parent_visited = 1;
    for (auto v : graph[u])
    {
        if (v == p && parent_visited)
        {
            parent_visited = 0;
            continue;
        }
        find_bridges(v, u, timer, visited, graph, intime, mintime, edges);
        mintime[u] = min(mintime[u], intime[v]);
        mintime[u] = min(mintime[u], mintime[v]);
        if (mintime[v] > intime[u])
            edges.push_back({u, v});
    }
}
void dfs(int u, int *visited, vector<vector<int>> &graph, int *component, int cn, vector<int> &mintime)
{
    if (visited[u])
        return;
    visited[u] = 1;
    component[u] = cn;
    for (auto v : graph[u])
    {
        if (mintime[u] == mintime[v])
        {

            dfs(v, visited, graph, component, cn, mintime);
        }
    }
}
void dfs(int u, int *visited, vector<vector<int>> &graph)
{
    if (visited[u])
        return;
    visited[u] = 1;
    // cout<<u<<" ";
    for (auto v : graph[u])
        if (!visited[v])
            cout << u << " " << v << endl, dfs(v, visited, graph);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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

    vector<int> intime(n + 1, -1);
    vector<int> mintime(n + 1, -1);
    vector<pair<int, int>> bridge_edges;
    int timer = 1;
    int visited[n + 1] = {};
    int cn = 0;
    int components[n + 1] = {};

    find_bridges(1, -1, timer, visited, graph, intime, mintime, bridge_edges);

    int visited3[n + 1] = {};
    for (auto it : bridge_edges)
    {
        int u = it.first, v = it.second;
        if (!visited3[u])
            cn++;
        dfs(u, visited3, graph, components, cn, mintime);
        if (!visited3[v])
            cn++;
        dfs(v, visited3, graph, components, cn, mintime);
    }
    vector<vector<int>> tree(n + 1);
    vector<vector<int>> vertices(n + 1);
    for (auto it : bridge_edges)
    {
        int u = it.first, v = it.second;
        tree[components[u]].push_back(components[v]);
        tree[components[v]].push_back(components[u]);
    }

    int visited2[cn + 1] = {};
    cout<<"bridge tree\n";
    dfs(1, visited2, tree);
    cout << endl;

    
}

/*
13 17
0 1
1 4
1 5
5 13
4 13
4 2
2 12
12 10
12 11
10 11
2 3
3 6
2 6
6 8
8 7
7 9
9 8

*/