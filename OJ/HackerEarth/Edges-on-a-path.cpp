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
void dfs(int u, int dest, int cnt, int *visited, vector<vector<int>> &graph, map<pair<int, int>, int> &mp)
{
    if (visited[u])
        return;
    visited[u] = 1;
    if (u == dest)
    {
        cout << cnt << endl;
        return;
    }

    for (auto v : graph[u])
    {
        if (mp[{u, v}] == 0)
        {
            dfs(v, dest, cnt, visited, graph, mp);
        }
        else
            dfs(v, dest, cnt + 1, visited, graph, mp);
    }
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int a, b;
    cin >> a >> b;

    vector<vector<int>> graph(n + 1);
    int i;
    int arr[n + 1] = {};
    for (i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
       
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
    int visited3[n+1]={};
    dfs(a,b,0,visited3,graph,mp);
}

/*



*/