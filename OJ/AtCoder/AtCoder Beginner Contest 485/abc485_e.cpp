#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define endl '\n'

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<int> visited(n + 1, 0);
    vector<vector<int>> color(n + 1, vector<int>(2, -1));
    queue<tuple<int, int, int>> q;

    visited[1] = 2;
    q.push({1, -1, 0});

    int ans_ = -1;

    while (!q.empty())
    {
        auto [u, pw, ans] = q.front();
        q.pop();

        if (u == n)
        {
            ans_ = ans;
            break;
        }

        for (auto it : graph[u])
        {
            int v = it.first;
            int w = it.second;

            if (w != pw && visited[v] < 2)
            {
                if (color[v][0] != w && color[v][1] != w)
                {
                    if (color[v][0] == -1)
                        color[v][0] = w;
                    else
                        color[v][1] = w;

                    visited[v]++;
                    q.push({v, w, ans + 1});
                }
            }
        }
    }

    cout << ans_ << endl;
    return 0;
}