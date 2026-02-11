#include <bits/stdc++.h>
using namespace std;
#define maxsize 200001
int parent[maxsize];
void makeSet(int n)
{
    parent[n] = n;
}
int findParent(int node)
{
    if (parent[node] == node)
        return node;
    else
        return parent[node] = findParent(parent[node]);
}
void makeUnion(int a, int b)
{
    int u = findParent(a);
    int v = findParent(b);
    if (u != v)
    {
        parent[u] = v;
    }
}
void minimumCostSpanningTree(int source, vector<vector<int>> &graph, map<pair<int, int>, int> &cost)
{
    int minimumSpanningTreeCost = 0;
    set<pair<int, pair<int, int>>> minimumCostEdge;
    for (auto destination : graph[source])
    {
        minimumCostEdge.insert({cost[{source, destination}], {source, destination}});
    }
    while (!minimumCostEdge.empty())
    {
        auto it = minimumCostEdge.begin();
        int u = it->second.first;
        int v = it->second.second;
        int Cost = it->first;
        minimumCostEdge.erase(it);
        if (findParent(u) != findParent(v))
        {
            makeUnion(u, v);
            minimumSpanningTreeCost += Cost;
            cout << u << " " << v << " " << Cost << endl;
            for (auto destination : graph[v])
            {
                if (findParent(v) != findParent(destination))
                    minimumCostEdge.insert({cost[{v, destination}], {v, destination}});
            }
        }
    }
    cout << "Minimum Spanning Tree Cost: " << minimumSpanningTreeCost << endl;
}
int32_t main()
{
    int n, e;
    cin >> n >> e;
    int i;
    for (i = 1; i <= n; i++)
    {
        makeSet(i);
    }
    map<pair<int, int>, int> cost;
    vector<vector<int>> graph(n + 1);
    for (i = 0; i < e; i++)
    {
        int u, v, Cost;
        cin >> u >> v >> Cost;
        graph[u].push_back(v);
        graph[v].push_back(u);
        cost[{u, v}] = Cost;
        cost[{v, u}] = Cost;
    }
    cout << endl
         << endl;
    minimumCostSpanningTree(8, graph, cost);

    return 0;
}