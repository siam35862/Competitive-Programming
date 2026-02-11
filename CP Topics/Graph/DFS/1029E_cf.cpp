#include <bits/stdc++.h>
using namespace std;
int ans = 0;
bool dfs(int u, vector<vector<int>> &g, vector<int> &visited, vector<int> &distance)
{
    visited[u] = 1;
    for (auto v : g[u])
    {
        if (visited[v] == 0)
        {
            distance[v] = min(distance[v], distance[u] + 1);
            bool f = dfs(v, g, visited, distance);
            if (f)
            {
                ans++;
                distance[u] = 1;
            }
        }
    }
    for (auto v : g[u])
    {
        distance[v] = min(distance[v], distance[u] + 1);
    }
    if (distance[u] > 2)
        return true;
    else
        return false;
}
signed main()
{

    int n, k;
    cin >> n;
    vector<vector<int>> g(n);
    int i;
    for (i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> visited(n, 0), distance(n, INT_MAX);
    int dist = 0;
    distance[0] = 0;
    dfs(0, g, visited, distance);
    cout << ans << endl;
    return 0;
}
/*
  Md. Siam Ahmed
  CSE, Khulna University
*/