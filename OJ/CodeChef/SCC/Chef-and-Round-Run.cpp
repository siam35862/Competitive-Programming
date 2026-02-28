#include <bits/stdc++.h>
using namespace std;

#define int long long

void dfs(int u, int cn, int &timer, stack<int> &st, vector<int> &visited, vector<int> &intime,
         vector<int> &mintime, vector<int> &roots, vector<vector<int>> &graph,
         vector<vector<int>> &components)
{
    intime[u] = mintime[u] = ++timer;
    st.push(u);

    for (auto v : graph[u])
    {
        if (intime[v] == -1)
        {
            dfs(v, cn, timer, st, visited, intime, mintime, roots, graph, components);
        }
        if (roots[v] == -1)
        {
            mintime[u] = min(mintime[u], mintime[v]);
        }
    }
    if (intime[u] == mintime[u])
    {
        components.push_back({u});
        cn++;
        while (!st.empty())
        {
            int v = st.top();
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
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> graph(n + 1), components;
        int a[n + 1], i;
       
        int ans=0;
        for (i = 1; i <= n; i++)
        {
            cin >> a[i];
            int next = i + a[i] + 1;
            next %= n;
            if (next == 0)
                next = n;
            graph[i].push_back(next);
            if (i == next)
                ans++;
        }

        vector<int> visited(n + 1, 0), intime(n + 1, -1), mintime(n + 1, -1), roots(n + 1, -1);
        int cn = 0, timer = 0;
        stack<int> st;
        for (i = 1; i <= n; i++)
        {
            if (intime[i] == -1)
                dfs(i, cn, timer, st, visited, intime, mintime, roots, graph, components);
        }
        for(auto &it:components)
        {
            if(it.size()>1)ans+=it.size();
        }
        cout<<ans<<endl;
    }
}