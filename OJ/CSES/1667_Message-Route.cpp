#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
void bfs(int src, vector<int> &ans, int *parent, vector<vector<int>> &graph)
{
    int visited[ans.size()] = {};
    queue<int> q;
    q.push(src);
    ans[src] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        visited[u] = 1;
        for (auto v : graph[u])
        {
            if (!visited[v])
            {
                parent[v] = u;
                q.push(v);
                visited[v] = 1;
                ans[v] = ans[u] + 1;
            }
        }
    }
}

int32_t main()
{
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
    vector<int> ans(n + 1, inf);
    int parent[n + 1];
    parent[1] = -1;
    bfs(1, ans, parent, graph);
    if (ans[n] == inf)
        cout << "IMPOSSIBLE\n";
    else
        
    {
        cout << ans[n] << endl;
        int u=n;
        deque<int>st;
        while(parent[u]!=-1)
        {
            st.push_front(u);
            u=parent[u];
        }
        st.push_front(1);
        for(auto it:st)cout<<it<<" ";
        cout<<endl;


    }
}