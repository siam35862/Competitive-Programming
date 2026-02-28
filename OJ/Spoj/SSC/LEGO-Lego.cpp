#include <bits/stdc++.h>

using namespace std;

#define int long long

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
int binarySearchL(int u, int L, int R, map<int, vector<vector<int>>> &mp)
{
    int ans = mp[u].size() - 1;
    int l = 0, r = ans;
    ans = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;

        if (mp[u][m][1] > L)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return ans;
}
int binarySearchR(int u, int L, int R, map<int, vector<vector<int>>> &mp)
{
    int ans = 0;
    int l = 0, r = mp[u].size() - 1;
    ans = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;

        if (mp[u][m][0] < R)
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return ans;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int i;

    vector<vector<int>> graph(n + 1), components;

    vector<vector<int>> v;
    for (i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back({b, a, d, c});
    }
    sort(v.begin(), v.end());

    map<int, vector<vector<int>>> topy;
    for (i = 0; i < n; i++)
    {
        int a, b, c, d;
        a = v[i][1];
        b = v[i][0];
        c = v[i][3];
        d = v[i][2];
        topy[d].push_back({a, c, i + 1});
    }
    for (auto &it : topy)
        sort(it.second.begin(), it.second.end());
    for (i = 0; i < n; i++)
    {
        int a, b, c, d;
        a = v[i][1];
        b = v[i][0];
        c = v[i][3];
        d = v[i][2];

        if (topy.find(b) != topy.end())
        {

            int l = binarySearchL(b, a, c, topy);
            int r = binarySearchR(b, a, c, topy);
            if (l != -1 && r != -1)
            {
                for (int j = l; j <= r; j++)
                {
                    int u = i + 1, v = topy[b][j][2];
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                    // cout<<u<<" "<<v<<endl;
                }
            }
        }
    }

    stack<int> st;
    vector<int> intime(n + 1, -1), mintime(n + 1, -1), roots(n + 1, -1);
    int timer = 0, cn = 0;
    for (i = 1; i <= n; i++)
    {
        if (intime[i] == -1)
            dfs(i, timer, cn, st, intime, mintime, roots, graph, components);
    }
    cout << components.size() << endl;
}