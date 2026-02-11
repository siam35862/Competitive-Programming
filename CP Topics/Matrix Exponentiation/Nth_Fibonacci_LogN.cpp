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
int cnt=0;
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
                    ///cnt++;
               }
               c[i][j] = v%M;
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

     int t;
     cin >> t;
     while (t--)
     {

          int n;
          cin >> n;
          if (n == 2 || n == 1)
               cout << n - 1 << endl;
          else
          {
               vector<vector<int>> a(2, vector<int>(2, 1));
               vector<vector<int>> b(2, vector<int>(1, 1));
               vector<vector<int>> c(2, vector<int>(1));
               a[1][1] = 0;
               b[1][0] = 0;

               int m = n - 1;

               a = matrix_exp(a, m);
               c = matrix_mul(a, b, 2, 2, 1);
               cout << c[1][0] << endl;
          }
     }

     

     return 0;
}
/*
  Md. Siam Ahmed
  CSE, Khulna University
*/

