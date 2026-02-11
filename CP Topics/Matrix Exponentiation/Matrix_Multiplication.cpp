#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define pb push_back
#define ppb pop_back()
#define tp top()
#define pp pop()
#define fr front()
#define pf push_front
#define pfb pop_front()
#define beg begin()
#define end end()
#define rbeg rbegin()
#define rend rend()
#define sz size()
#define len length()
#define endl '\n'
#define srt(v) sort(v.beg, v.end)
#define rsrt(v) sort(v.rbeg, v.rend)
#define rev(v) reverse(v.beg, v.end)
#define maxsize 200005
#define M 1000000007

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_setd = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     int a, b, c, d;
     cin >> a >> b;
     vector<vector<int>> m1(a, vector<int>(b));
     int i, j;
     for (i = 0; i < a; i++)
     {
          for (j = 0; j < b; j++)
               cin >> m1[i][j];
     }

     cin >> c >> d;
     vector<vector<int>> m2(c, vector<int>(d));
     for (i = 0; i < c; i++)
     {
          for (j = 0; j < d; j++)
               cin >> m2[i][j];
     }

     if (b != c)
     {
          cout << "Matrxi Multiplication is impossible.\n";
     }
     else
     {
          vector<vector<int>> m = matrix_mul(m1, m2, a, b, d);

          for (i = 0; i < a; i++)
          {
               for (j = 0; j < d; j++)
                    cout << m[i][j] << " ";
               cout << endl;
          }
     }

     return 0;
}
/*
  Md. Siam Ahmed
  CSE, Khulna University
*/
