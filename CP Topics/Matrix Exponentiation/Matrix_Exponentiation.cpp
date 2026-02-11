#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrix_mul(vector<vector<int>> &a, vector<vector<int>> &b, int n, int m, int k)
{
     vector<vector<int>> c(n, vector<int>(k));
     int i, j;
     int x;
     for (i = 0; i < n; i++)
     {
          for (j = 0; j < k; j++)
          {
               int v = 0;
               for (x = 0; x < m; x++)
               {
                    v += a[i][x] * b[x][j];
               }
               c[i][j] = v;
          }
     }
     return c;
}

vector<vector<int>> matrix_exp(vector<vector<int>> &a, int n)
{
     vector<vector<int>> b;
     int m = a.size();
     if (n == 0)
     {

          b.resize(m, vector<int>(m, 0));
          for (int i = 0; i < m; i++)
               b[i][i] = 1;
          return b;
     }

     b = matrix_exp(a, n / 2);
     b = matrix_mul(b, b, m, m, m);
     if (n % 2 == 0)
          return b;
     else
     {
          b = matrix_mul(b, a, m, m, m);
          return b;
     }
}

int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     int n;
     int m;
     cin >> n >> m;
     vector<vector<int>> a(n, vector<int>(n));
     int i, j;

     for (i = 0; i < n; i++)
     {
          for (j = 0; j < n; j++)
          {
               cin >> a[i][j];
          }
     }

     vector<vector<int>> b = matrix_exp(a, m);
     for(auto it:b)
     {
          for(auto v:it)cout<<v<<" ";
          cout<<endl;
     }

     return 0;
}
/*
  Md. Siam Ahmed
  CSE, Khulna University
*/
