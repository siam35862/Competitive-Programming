#include <bits/stdc++.h>
using namespace std;

void find_bridges(int u, int p, int &timer, int *visited, vector<vector<int>> &graph,
                  vector<int> &intime, vector<int> &mintime, vector<pair<int, int>> &edges)
{

    visited[u] = 1;
    intime[u] = mintime[u] = timer;
    // cout << u << " mintime " << mintime[u] << endl;

    timer++;
    int parent_visited = 1;
    for (auto v : graph[u])
    {
        if (v == p && parent_visited)
        {
            parent_visited = 0;
            continue;
        }
        if (visited[v])
        {
            mintime[u] = min(mintime[u], intime[v]);
        }
        else
        {
            find_bridges(v, u, timer, visited, graph, intime, mintime, edges);

            mintime[u] = min(mintime[u], mintime[v]);
            if (mintime[v] > intime[u])
                edges.push_back({u, v}), edges.push_back({v, u});
        }
    }
}
void dfs(int u, int *visited, vector<vector<int>> &graph, int *component, int cn, map<pair<int, int>, int> &mp)
{
    if (visited[u])
        return;
    visited[u] = 1;
    component[u] = cn;
    for (auto v : graph[u])
    {
        if (mp[{u, v}] == 0)
        {
            dfs(v, visited, graph, component, cn, mp);
        }
    }
}
pair<int, int> bfs(int u, vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> distance(n + 1, -1);
    queue<int> q;
    q.push(u);
    distance[u] = 0;
    int mx = 0;
    int ind = -1;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (auto v : graph[u])
        {
            if (distance[v] == -1)
            {
                q.push(v);
                distance[v] = distance[u] + 1;
                if (distance[v] > mx)
                {
                    mx = distance[v];
                    ind = v;
                }
            }
        }
    }
    return {ind, mx};
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
    int arr[n + 1] = {};
    for (i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u += 1;
        v += 1;
        if (u == v)
            arr[u] += 1;
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
    for (i = 1; i <= n; i++)
    {
        find_bridges(i, -1, timer, visited, graph, intime, mintime, bridge_edges);
    }
    map<pair<int, int>, int> mp;
    for (auto it : bridge_edges)
        mp[it] = 1;
    int visited3[n + 1] = {};

    for (i = 1; i <= n; i++)
    {
        int u = i;
        if (!visited3[u])
        {
            cn++;
            dfs(u, visited3, graph, components, cn, mp);
        }
    }
    vector<vector<int>> tree(n + 1);
    vector<vector<int>> vertices(n + 1);
    for (i = 1; i <= n; i++)
        vertices[components[i]].push_back(i);
    int len = 0;

    for (i = 1; i <= n; i++)
    {
        if (vertices[i].size() > 0)
            len++;
        
    }
    cout << len << endl;

    for (i = 1; i <= n; i++)
    {
        if (vertices[i].size() > 0)
        {
            cout << vertices[i].size() << " ";
            for (auto it : vertices[i])
                cout << it - 1 << " ";
            cout << endl;
        }
        
    }
}

/*
5 5
1 2
2 3
3 1
4 1
5 2


*/