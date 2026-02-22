#include <bits/stdc++.h>

using namespace std;

void bfs(int r, int c, int val, vector<vector<int>> &grid)
{
    int n = grid.size();
    int st = grid[r][c];
    queue<pair<int, int>> q;
    map<pair<int, int>, int> visited;
    q.push({r, c});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        if (!visited[p])
        {
            visited[p] = 1;
            grid[p.first][p.second]=val;
            for (int i = -1; i <= 1; i++)
            {
                int j;
                for (j = -1; j <= 1; j++)
                {
                    if (i == 0)
                    {
                        r = p.first + i;
                        c = p.second + j;
                        
                        
                        if (c>=0&&c<n&&!visited[{r, c}]&&grid[r][c]==st)
                            q.push({r, c});
                    }
                    if (j == 0)
                    {
                        r = p.first + i;
                        c = p.second + j;
                        if (r>=0&&r<n&&!visited[{r, c}]&&grid[r][c]==st)
                            q.push({r, c});
                    }
                }
            }
        }
    }
}
int32_t main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int r, c;
    cin >> r >> c;
    int val;
    cin>>val;
    bfs(r,c,val,grid);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
/*
4
0 0 1 0
1 1 0 0
0 0 0 0 
0 1 1 1 

*/