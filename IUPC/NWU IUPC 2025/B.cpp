#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    

    int n;
    cin >> n;
    vector<string> s(n);
    int i;
    for (i = 0; i < n; i++)
        cin >> s[i];
    

    int p, q, x, y;
    int j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (s[i][j] == 'K')
            {
                x = i;
                y = j;
            }
            if (s[i][j] == 'Q')
            {
                p = i;
                q = j;
            }
        }
    }

    vector<vector<int>> ans(n, vector<int>(n, inf));

    queue<pair<pair<int, int>, int>> qq;
    ans[p][q] = 0;
    qq.push({{p, q}, 0});

    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    vector<vector<pair<int,int>>> marked(n, vector<pair<int,int>>(n, {0,0}));
   
    while (!qq.empty())
    {

        auto it = qq.front();
        qq.pop();
        int a = it.first.first, b = it.first.second;
        int d = it.second;

        // cout<<a<<" "<<b<<" "<<d<<endl;
       
            visited[a][b] = 1;
           

            if (!marked[a][b].first)
            {
                for (j = b + 1; j < n; j++)
                {
                    marked[a][j].first=1;
                   
                    if (s[a][j] == '#')
                        break;
                    if (!visited[a][j])
                    {
                        ans[a][j] = min(ans[a][j], ans[a][b] + 1);
                        qq.push({{a, j}, 1});
                        visited[a][j] = 1;
                        
                    }
                }
                for (j = b - 1; j >= 0; j--)
                {
                     marked[a][j].first=1;
                    
                    if (s[a][j] == '#')
                        break;
                    if (!visited[a][j])
                    {

                        ans[a][j] = min(ans[a][j], ans[a][b] + 1);
                        qq.push({{a, j}, 1});
                        visited[a][j] = 1;
                       
                    }
                }
            }
            if (!marked[a][b].second)
            {
                for (int k = 1; k < n; k++)
                {
                    
                    
                    if (a - k >= 0 && b + k < n)
                    {
                        marked[a-k][b+k].second=1;
                        if (s[a - k][b + k] == '#')
                            break;
                        if (!visited[a - k][b + k])
                        {
                            ans[a - k][b + k] = min(ans[a - k][b + k], ans[a][b] + 1);
                            qq.push({{a - k, b + k}, 2});
                            visited[a - k][b + k] = 1;
                            
                        }
                    }
                    else
                        break;
                }
                for (int k = -1; k >= -n; k--)
                {
                    
                    
                    if (a - k < n && b + k >= 0)
                    {
                        marked[a-k][b+k].second=1;
                        if (s[a - k][b + k] == '#')
                            break;
                        if (!visited[a - k][b + k])
                        {
                            ans[a - k][b + k] = min(ans[a - k][b + k], ans[a][b] + 1);
                            qq.push({{a - k, b + k}, 2});
                            visited[a - k][b + k] = 1;
                            
                        }
                    }
                    else
                        break;
                }
            }
        
    }

    if (ans[x][y] == inf)
        cout << -1 << endl;
    else
        cout << ans[x][y] << endl;
   
}
