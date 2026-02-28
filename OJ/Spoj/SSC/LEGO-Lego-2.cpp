#include <bits/stdc++.h>

using namespace std;

#define int long long

#define maxN 200005

int parent[200005];

void makeSet(int n)
{
    int i;
    for (i = 1; i <= n; i++)
        parent[i] = i;
}
int findParent(int u)
{
    if (u != parent[u])
        return parent[u] = findParent(parent[u]);
    return parent[u];
}
void Union(int a, int b)
{
    int u = findParent(a), v = findParent(b);
    if (u != v)
    {
        parent[v] = u;
    }
}

int binarySearchL(int u, int L, int R, map<int, vector<vector<int>>> &topy)
{
    int ans = topy[u].size() - 1;
    int l = 0, r = ans;
    ans = -1;

    while (l <= r)
    {
        int m = (l + r) / 2;

        if (topy[u][m][1] > L)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return ans;
}
int binarySearchR(int u, int L, int R, map<int, vector<vector<int>>> &topy)
{
    int ans = 0;
    int l = 0, r = topy[u].size() - 1;
    ans = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;

        if (topy[u][m][0] < R)
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return ans;
}
void dfs(int u, int *visited, vector<vector<int>> &graph)
{
    if (visited[u])
        return;
    visited[u] = 1;
    for (auto v : graph[u])
        dfs(v, visited, graph);
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int i;
    makeSet(n);

    vector<vector<int>> v;
    for (i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back({b, a, d, c});
    }

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
           // cout<<i+1<<" "<<l<<" "<<r<<endl;
            if (l != -1 && r != -1)
            {
                for (int j = l; j <= r; j++)
                {

                    int u = i + 1, v = topy[b][j][2];
                    Union(u, v);
                   // cout << u << " " << v << endl;
                }
            }
        }
    }

    int ans = 0;
    int visited[n + 1] = {};
    for (i = 1; i <= n; i++)
    {
        if (visited[findParent(i)] == 0)
        {
            ans++;
            visited[findParent(i)] = 1;
        }
    }
    cout << ans << endl;
}

/*
12
0 0 1 1
1 0 2 1
2 0 4 1
4 0 5 3
5 0 6 2
0 1 1 2
1 1 2 2
2 1 4 2
0 2 4 3
0 3 5 4
5 4 6 5
6 3 8 4

9
0 0 1 1
1 0 2 1
2 0 4 1
4 0 5 3
0 1 1 2
1 1 2 2
2 1 4 2
0 2 4 3
0 3 1 4

8
0 0 1 1
1 0 2 1
2 0 4 1
4 0 5 3
0 1 1 2
1 1 2 2
2 1 4 2
0 3 5 4

8
0 0 1 1
1 0 2 1
2 0 4 1
4 0 5 3
0 1 1 2
1 1 2 2
2 1 4 2
0 2 4 3

*/