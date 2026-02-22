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
int32_t main()
{
    int n, e;
    cin >> n >> e;
    int i;
    for (i = 1; i <= n; i++)
    {
        makeSet(i);
    }
    vector<pair<int, pair<int, int>>> edge;
    for (i = 0; i < e; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        edge.push_back({cost, {u, v}});
    }
    sort(edge.begin(), edge.end());
    int minimumSpanningTreeCost = 0;
    
    cout<<endl<<endl;
    for (i = 0; i < e; i++)
    {
       
        int a = edge[i].second.first;
        int b = edge[i].second.second;
        if (findParent(a) != findParent(b))
        {
            cout<<a<<" "<<b<<" "<<" "<<edge[i].first<<endl;
            minimumSpanningTreeCost += edge[i].first;
            makeUnion(a, b);
        }
    }
    cout << "Minimum Spanning Tree Cost: " << minimumSpanningTreeCost << endl;
    return 0;
}