#include <bits/stdc++.h>
using namespace std;

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
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1), components;
    vector<pair<int, int>> edges(m + 1);
    int i, j;
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
   for(i=1;i<=n;i++)
   {
      if(components[roots[i]-1].size()>1)cout<<1<<" ";
      else cout<<0<<" ";
   }
   cout<<endl;
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